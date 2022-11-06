import sys
import pygame
import os
import random

pygame.init()
pygame.display.set_caption("Coffee game")

SIZE = (WIDTH, HEIGHT) = (450, 450)
screen = pygame.display.set_mode(SIZE)

clock = pygame.time.Clock()

max_speed = 7
price_count_speed = 30
count_kofe_on_field = 10
price_count_coffee = 30
coffee_count = 0

get_coffee = False
is_alive = True
mus = pygame.mixer.Sound("data/bgmusic.mp3")


def restart():
    global max_speed, price_count_speed, count_kofe_on_field, \
        price_count_coffee, coffee_count, get_coffee, is_alive

    max_speed = 7
    price_count_speed = 30
    count_kofe_on_field = 10
    price_count_coffee = 30
    coffee_count = 0

    get_coffee = False
    is_alive = True


def terminate():
    pygame.quit()
    sys.exit()


def fill_gradient(surface, color, gradient, rect=None, vertical=True, forward=True):
    if rect is None:
        rect = surface.get_rect()
    x1, x2 = rect.left, rect.right
    y1, y2 = rect.top, rect.bottom
    if vertical:
        h = y2 - y1
    else:
        h = x2 - x1
    if forward:
        a, b = color, gradient
    else:
        b, a = color, gradient
    rate = (
        float(b[0] - a[0]) / h,
        float(b[1] - a[1]) / h,
        float(b[2] - a[2]) / h
    )
    fn_line = pygame.draw.line
    if vertical:
        for line in range(y1, y2):
            color = (
                min(max(a[0] + (rate[0] * (line - y1)), 0), 255),
                min(max(a[1] + (rate[1] * (line - y1)), 0), 255),
                min(max(a[2] + (rate[2] * (line - y1)), 0), 255)
            )
            fn_line(surface, color, (x1, line), (x2, line))
    else:
        for col in range(x1, x2):
            color = (
                min(max(a[0] + (rate[0] * (col - x1)), 0), 255),
                min(max(a[1] + (rate[1] * (col - x1)), 0), 255),
                min(max(a[2] + (rate[2] * (col - x1)), 0), 255)
            )
            fn_line(surface, color, (col, y1), (col, y2))


def load_image(name, colorkey=None):
    fullname = os.path.join('data', name)
    if not os.path.isfile(fullname):
        print(f"Файл с изображением '{fullname}' не найден")
        sys.exit()
    image = pygame.image.load(fullname)
    if name == 'status_bar.png':
        colorkey = image.get_at((45, 35))
    if colorkey is not None:
        image = image.convert()
        if colorkey == -1:
            colorkey = image.get_at((0, 0))
        image.set_colorkey(colorkey)
    else:
        image = image.convert_alpha()
    if 'fon' in name:
        image = pygame.transform.scale(image,
                                       (450, 1350))  # тут идет обрезка изображений, а то изначально они гигантские
    elif name == 'kofe1.png':
        image = pygame.transform.scale(image, (40, 40))
    elif name == 'rectangle.png':
        image = pygame.transform.scale(image, (150, 26))
    elif name == 'kofe.png':
        image = pygame.transform.scale(image, (80, 80))
    return image


class Music(pygame.sprite.Sprite):

    def __init__(self, mus_playing):
        super(Music, self).__init__()

        self.image = load_image('play.svg')
        self.rect = self.image.get_rect()

        self.rect.x = 350
        self.rect.y = -5

        self.mus_playing = mus_playing

    def update(self):
        if self.mus_playing:  # play
            self.image = load_image('play.svg')
        else:
            self.image = load_image('stop.svg')


ms = Music(True)
status_bar_objects = pygame.sprite.Group()
status_bar_objects.add(ms)
pygame.mixer.Sound.play(mus)


def start_background():
    title = 'COFFEE GAME'
    fill_gradient(screen, (32, 191, 85), (1, 186, 239))

    font = pygame.font.Font(None, 70)
    string_rendered = font.render(title, True, pygame.Color((0, 4, 91)))
    intro_rect = string_rendered.get_rect()
    intro_rect.centerx = 225
    intro_rect.y = 100
    screen.blit(string_rendered, intro_rect)

    pygame.draw.rect(screen, (36, 221, 198), (50, 200, 350, 100))
    pygame.draw.rect(screen, (0, 4, 91), (50, 200, 350, 100), width=5)

    title = 'НАЧАТЬ'
    font = pygame.font.Font(None, 70)
    string_rendered = font.render(title, True, pygame.Color((0, 4, 91)))
    intro_rect = string_rendered.get_rect()
    intro_rect.centerx = 225
    intro_rect.y = 220
    screen.blit(string_rendered, intro_rect)

    title = 'Анекдот'
    font = pygame.font.Font(None, 70)
    string_rendered = font.render(title, True, pygame.Color((0, 4, 91)))
    intro_rect = string_rendered.get_rect()
    intro_rect.centerx = 225
    intro_rect.y = 335
    start_x = intro_rect.x
    delta_x = intro_rect.width
    start_y = intro_rect.y
    delta_y = intro_rect.height

    screen.blit(string_rendered, intro_rect)

    return start_x, delta_x, start_y, delta_y


def start_screen():
    global ms, status_bar_objects, clock

    pygame.mixer.Sound.play(mus)

    while True:
        start_x, delta_x, start_y, delta_y = start_background()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                terminate()
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if 50 <= event.pos[0] <= 400 and 200 <= event.pos[1] <= 300:
                    return
                if start_x <= event.pos[0] <= start_x + delta_x and \
                        start_y <= event.pos[1] <= start_y + delta_y:
                    anekdot()
                if 380 <= event.pos[0] <= 430 and 0 <= event.pos[1] <= 50:
                    if not ms.mus_playing:
                        mus.set_volume(100)
                        ms.mus_playing = True
                    else:
                        mus.set_volume(0)
                        ms.mus_playing = False

        status_bar_objects.update()
        status_bar_objects.draw(screen)
        pygame.display.flip()
        clock.tick(25)


def anekdot():
    fon = pygame.transform.scale(load_image('fon_new.jpg'), (WIDTH, HEIGHT))
    screen.blit(fon, (0, 0))
    pygame.draw.rect(screen, (145, 192, 244), (0, 0, 450, 60))
    pygame.draw.line(screen, (0, 4, 91), (0, 60), (450, 60), width=5)

    font = pygame.font.Font(None, 70)
    title = 'АНЕКДОТ'
    string_rendered = font.render(title, True, pygame.Color((0, 4, 91)))
    intro_rect = string_rendered.get_rect()
    intro_rect.centerx = 225
    intro_rect.y = 10
    screen.blit(string_rendered, intro_rect)

    intro_text = ['Слава Комиссаренко', '', 'Ходить в супермаркеты, это огромный стресс. Например,',
                  'бывает, ты идёшь в супермаркет, чтобы купить бананов,',
                  'заходишь — бананов не оказывается, теперь тебе надо', 'идти домой, но теперь ты не можешь выйти',
                  'из супермаркета, потому что у тебя нет покупок и',
                  'ты боишься, что охранник подумает, что ты что-то украл.',
                  'И ты думаешь: «Ладно, хорошо, буду выходить', 'максимально медленно и с честным лицом, чтобы',
                  'охранник не подумал, что я что-то украл». И это очень',
                  'сложная актёрская задача, потому что тебе надо', 'выражением лица объяснить охраннику, почему ты',
                  'ничего не купил, и ты идёшь такой: «Не было бананов,',
                  'кто бы подумать...» Реально, проще купить что-нибудь',
                  'на кассе, отдать кассиру, расплатиться и выйти.']

    font = pygame.font.Font(None, 23)
    text_coord = 80
    for line in intro_text:
        string_rendered = font.render(line, True, pygame.Color((0, 4, 91)))
        intro_rect = string_rendered.get_rect()
        text_coord += 5
        intro_rect.top = text_coord
        intro_rect.x = 10
        text_coord += intro_rect.height
        screen.blit(string_rendered, intro_rect)

    pygame.draw.rect(screen, (145, 192, 244), (350, 415, 90, 25))
    pygame.draw.rect(screen, (0, 4, 91), (350, 415, 90, 25), width=2)

    intro_text = 'Назад'
    font = pygame.font.Font(None, 30)
    sprite = pygame.sprite.Sprite()
    sprite.image = font.render(intro_text, True, [0, 4, 91])
    sprite.rect = sprite.image.get_rect()
    sprite.rect.x = 364
    sprite.rect.y = 418
    screen.blit(sprite.image, sprite.rect)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                terminate()
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if 350 <= event.pos[0] <= 440 and 415 <= event.pos[1] <= 440:
                    start_screen()
                    return
        pygame.display.flip()


class Player(pygame.sprite.Sprite):
    def __init__(self, max_speed):
        super(Player, self).__init__()

        self.image = load_image('kofe.png')
        self.rect = self.image.get_rect()

        self.rect.centerx = WIDTH / 2
        self.rect.centery = HEIGHT / 2

        self.max_speed = max_speed

    def update(self, max_speed):
        global get_coffee, is_alive, coffee_count

        if self.max_speed > 0:
            self.max_speed = max_speed
        else:
            self.max_speed = -max_speed

        self.rect.x += self.max_speed
        if self.rect.x >= 450 - 80:
            self.max_speed = -self.max_speed
            self.image = pygame.transform.flip(self.image, True, False)
        if self.rect.x <= 0:
            self.max_speed = -self.max_speed
            self.image = pygame.transform.flip(self.image, True, False)
        if pygame.sprite.spritecollide(self, kofe_objects, False) and is_alive:
            pygame.sprite.spritecollide(self, kofe_objects, True)
            coffee_count += 1
            get_coffee = True


class Background(pygame.sprite.Sprite):
    def __init__(self, max_speed):
        super(Background, self).__init__()

        self.image = load_image('fon_4.jpg')
        self.rect = self.image.get_rect()
        self.rect.bottom = 900

        self.max_speed = max_speed
        self.current_speed = -self.max_speed

    def update(self, max_speed):
        if self.max_speed > 0:
            self.max_speed = max_speed
        else:
            self.max_speed = -max_speed

        keys = pygame.key.get_pressed()
        if is_alive:
            if keys[pygame.K_UP]:
                self.current_speed = self.max_speed
        self.current_speed -= 0.1
        self.rect.bottom += self.current_speed

        if self.rect.bottom >= 1350:
            self.rect.bottom = 900
        if self.rect.bottom <= 450:
            self.rect.bottom = 900


class Kofe(pygame.sprite.Sprite):
    def __init__(self, x, y, max_speed):
        super(Kofe, self).__init__()

        self.image = load_image('kofe1.png')
        self.rect = self.image.get_rect()

        self.rect.x = (random.randint(x, x + 400))
        self.rect.y = (random.randint(y, y + 400))

        self.max_speed = max_speed

        self.current_speed = -self.max_speed

    def update(self, count, max_speed):
        if max_speed != self.max_speed:
            for i in kofe_objects:
                i.change_speed(max_speed)
        keys = pygame.key.get_pressed()
        if is_alive:
            if keys[pygame.K_UP]:
                self.current_speed = self.max_speed
            for i in kofe_objects:
                if i.rect.top >= 450:
                    kofe_objects.remove(i)
                    kofe_objects.add(Kofe(0, -450, max_speed))
            if count > len(list(kofe_objects)):
                for i in range(count - len(list(kofe_objects))):
                    kofe_objects.add(Kofe(0, -450, max_speed))
        self.current_speed -= 0.1
        self.rect.bottom += self.current_speed

    def change_speed(self, speed):
        self.max_speed = speed


class Buttons(pygame.sprite.Sprite):
    def __init__(self, name, x):
        super(Buttons, self).__init__()

        self.image = load_image(name)
        self.rect = self.image.get_rect()

        self.rect.x = x
        self.rect.y = 385


class Button_text(pygame.sprite.Sprite):
    def __init__(self, count, x, y, size):
        super(Button_text, self).__init__()

        intro_text = str(count)

        self.size = size
        font = pygame.font.Font(None, self.size)
        self.image = font.render(intro_text, True, [255, 255, 255])
        self.rect = self.image.get_rect()

        self.rect.centerx = x
        self.rect.y = y

    def update(self, count):
        intro_text = str(count)
        font = pygame.font.Font(None, self.size)
        self.image = font.render(intro_text, True, [255, 255, 255])


class RunningLine(pygame.sprite.Sprite):

    def __init__(self):
        super(RunningLine, self).__init__()

        self.image = load_image('rectangle.png')
        self.rect = self.image.get_rect()

        self.rect.x = 5
        self.rect.y = 399
        self.speed = 2

    def update(self):
        global is_alive
        global get_coffee

        if is_alive and get_coffee:
            self.rect.x = 5
            self.rect.y = 399
            get_coffee = False
        if self.rect.x < -150:
            self.speed = 0
            is_alive = False
        self.rect.x -= self.speed


class Count_Coffee(pygame.sprite.Sprite):

    def __init__(self, count_coffee):
        super(Count_Coffee, self).__init__()

        intro_text = str(count_coffee)

        font = pygame.font.Font(None, 100)
        self.image = font.render(intro_text, True, [0, 4, 91])
        self.rect = self.image.get_rect()

        self.rect.centerx = 225
        self.rect.y = 10

    def update(self, count_coffee):
        intro_text = str(count_coffee)

        font = pygame.font.Font(None, 100)
        self.image = font.render(intro_text, True, [0, 4, 91])


class Retry(pygame.sprite.Sprite):
    def __init__(self):
        super(Retry, self).__init__()

        intro_text = "Заново"

        font = pygame.font.Font(None, 30)
        self.image = font.render(intro_text, True, [0, 4, 91])
        self.rect = self.image.get_rect()

        self.rect.x = 12
        self.rect.y = 8


running = True
start_screen()

player = Player(max_speed)
background = Background(max_speed)
rl = RunningLine()
if ms.mus_playing:
    ms = Music(True)
else:
    ms = Music(False)
ms.update()
score = Count_Coffee(coffee_count)
retry = Retry()

all_objects = pygame.sprite.Group()
kofe_objects = pygame.sprite.Group()
button_count_coffee = pygame.sprite.Group()
button_speed = pygame.sprite.Group()
counter = pygame.sprite.Group()
for i in status_bar_objects:
    status_bar_objects.remove(i)

counter.add(score)
counter.add(retry)

sprite = pygame.sprite.Sprite()
sprite.image = load_image("status_bar_bg.png")
sprite.rect = sprite.image.get_rect()
sprite.rect.bottom = 450
status_bar_objects.add(sprite)
status_bar_objects.add(rl)
sprite = pygame.sprite.Sprite()
sprite.image = load_image("status_bar.png")
sprite.rect = sprite.image.get_rect()
sprite.rect.bottom = 450
status_bar_objects.add(sprite)

btn1 = Buttons('btn1_count.png', 340)
button_count_coffee.add(btn1)
text1_1 = Button_text(count_kofe_on_field, 400, 393, 25)
button_count_coffee.add(text1_1)
text1_2 = Button_text(price_count_coffee, 373, 410, 50)
button_count_coffee.add(text1_2)

btn2 = Buttons('btn2_speed.png', 240)
button_speed.add(btn2)
text2_1 = Button_text(max_speed, 300, 393, 25)
button_speed.add(text2_1)
text2_2 = Button_text(price_count_speed, 273, 410, 50)
button_speed.add(text2_2)

all_objects.add(background)
all_objects.add(player)

status_bar_objects.add(ms)

# pygame.mixer.Sound.play(mus)

for i in range(count_kofe_on_field):
    kofe_objects.add(Kofe(0, 0, max_speed))

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.MOUSEBUTTONDOWN:
            if 380 <= event.pos[0] <= 430 and 0 <= event.pos[1] <= 50:
                if not ms.mus_playing:
                    mus.set_volume(100)
                    ms.mus_playing = True
                else:
                    mus.set_volume(0)
                    ms.mus_playing = False
                ms.update()
            if (340 <= event.pos[0] <= 426 and 385 <= event.pos[
                1] <= 445 and is_alive and count_kofe_on_field < 70 and coffee_count >= price_count_coffee):
                coffee_count -= price_count_coffee
                price_count_coffee *= 2
                count_kofe_on_field += 10
                text1_1.update(count_kofe_on_field)
                if count_kofe_on_field >= 70:
                    text1_2.update('MAX')
                else:
                    text1_2.update(price_count_coffee)
            if (240 <= event.pos[0] <= 326 and 385 <= event.pos[
                1] <= 445 and is_alive and max_speed < 16 and coffee_count >= price_count_speed):
                coffee_count -= price_count_speed
                price_count_speed *= 2
                max_speed += 3
                text2_1.update(max_speed)
                if max_speed >= 16:
                    text2_2.update('MAX')
                else:
                    text2_2.update(price_count_speed)
            if 5 <= event.pos[0] <= 95 and 5 <= event.pos[1] <= 30:
                dog_surf = load_image('fon_black.jpg')
                dog_rect = dog_surf.get_rect(
                    bottomright=(450, 450))
                screen.blit(dog_surf, dog_rect)
                pygame.display.update()
                pygame.time.delay(100)

                restart()

                player = Player(max_speed)
                background = Background(max_speed)

                if ms.mus_playing:
                    ms = Music(True)
                else:
                    ms = Music(False)
                ms.update()

                for i in kofe_objects:
                    kofe_objects.remove(i)

                for i in range(count_kofe_on_field):
                    kofe_objects.add(Kofe(0, 0, max_speed))

                for i in status_bar_objects:
                    status_bar_objects.remove(i)

                sprite = pygame.sprite.Sprite()
                sprite.image = load_image("status_bar_bg.png")
                sprite.rect = sprite.image.get_rect()
                sprite.rect.bottom = 450
                status_bar_objects.add(sprite)
                rl = RunningLine()
                status_bar_objects.add(rl)
                sprite = pygame.sprite.Sprite()
                sprite.image = load_image("status_bar.png")
                sprite.rect = sprite.image.get_rect()
                sprite.rect.bottom = 450
                status_bar_objects.add(sprite)
                status_bar_objects.add(ms)

                text1_1.update(count_kofe_on_field)
                text1_2.update(price_count_coffee)
                text2_1.update(max_speed)
                text2_2.update(price_count_speed)

                player.rect.centerx = WIDTH / 2
                player.rect.centery = HEIGHT / 2

    all_objects.update(max_speed)
    kofe_objects.update(count_kofe_on_field, max_speed)
    rl.update()
    counter.update(coffee_count)

    all_objects.draw(screen)
    kofe_objects.draw(screen)
    status_bar_objects.draw(screen)
    button_count_coffee.draw(screen)
    button_speed.draw(screen)

    pygame.draw.rect(screen, (145, 192, 244), (5, 5, 90, 25))
    pygame.draw.rect(screen, (0, 4, 91), (5, 5, 90, 25), width=2)
    counter.draw(screen)

    pygame.display.flip()
    clock.tick(25)
pygame.quit()
