import telebot
import pickle
from telebot import types


# Задается токен
Bot = telebot.TeleBot("5772093592:AAEUEST7p82vGV6dwfRnaqd44RMK57yavbY")

BANNED_NAMES = ["IDDQD", "DQDDI", "Вернуться", "Подтвердить", "IVALTEK"]
users_dict = {}
QUEUE = []

#----------------> РАБОТА С ФАЙЛАМИ <---------------------
txt = open("DATA.pickle").read()
if txt == "": with open('DATA.pickle', 'wb') as f: pickle.dump(users_dict, f)
else:
    with open('DATA.pickle', 'rb') as f: users_dict = pickle.load(f)
    for user in users_dict.keys():
        for argument in users_dict[user].keys():
            if argument == "ExecuteStatus": users_dict[user][argument] = False
            elif argument == "Cash": users_dict[user][argument] = ""
            elif argument == "InQueueStatus": users_dict[user][argument] = False
            elif argument == "Homerun": users_dict[user][argument] = "New"
            elif argument == "Location":
                if users_dict[user]["Admin"] == True: users_dict[user][argument] = "Admin_Main"
                else: users_dict[user][argument] = "Main"
    with open('DATA.pickle', 'wb') as f: pickle.dump(users_dict, f)



#----------------> ФУНКЦИИ <---------------------
def initialize_user(USER_ID, message):
    """Производит начальную инициализацию пользователя

    :argument USER_ID: ID пользователя"""
    
    if USER_ID in users_dict.keys():
        if users_dict[USER_ID]["Homerun"] == "New": initialize_menu(message, "Приветствую товарищ!\nЧто тебе нужно?", users_dict[USER_ID]["Location"])
            
    else:
        user_tag = message.from_user.username
        users_dict[USER_ID] = {"Name": "",
                               "ExecuteStatus": False,
                               "NameChangeStatus": False,
                               "Cash": "",
                               "InQueueStatus": False,
                               "Admin": False,
                               "Tag": user_tag,
                               "Location":"Main",
                               "Homerun":"New"}
        initialize_menu(message, "Приветствую товарищ!\nЧто тебе нужно?", users_dict[USER_ID]["Location"])


def welcome_in_queue(USER_ID):
    """Добавляет в очередь пользователя

    :argument USER_ID: ID пользователя"""
    
    if users_dict[USER_ID]["Name"] == "":
        users_dict[USER_ID]["InQueueStatus"] = True
        users_dict[USER_ID]["ExecuteStatus"] = False
        users_dict[USER_ID]["Name"] = users_dict[USER_ID]["Cash"]
        users_dict[USER_ID]["Cash"] = ""
        QUEUE.append(users_dict[USER_ID]["Name"] + "_" + str(USER_ID))
    else:
        users_dict[USER_ID]["InQueueStatus"] = True
        users_dict[USER_ID]["ExecuteStatus"] = False
        users_dict[USER_ID]["Cash"] = ""
        QUEUE.append(users_dict[USER_ID]["Name"] + "_" + str(USER_ID))

# !ВНИМАНИЕ!  -->  Здесь надо за место USER_ID  ТОЛЬКО мое ID. Узнать, заменить.
def welcome_king(USER_ID):
    """Добавляет меня

    :argument USER_ID: ID пользователя"""

    users_dict[USER_ID]["InQueueStatus"] = True
    users_dict[USER_ID]["ExecuteStatus"] = False
    users_dict[USER_ID]["Name"] = "Слесарчук"
    users_dict[USER_ID]["Cash"] = ""
    QUEUE.insert(0, users_dict[USER_ID]["Name"] + "_" + str(USER_ID))


def initialize_menu(message_arg, text, USER_LOC):
    """Функция ининцализирующая главное меню учитывая статусы

    :argument message_arg: передай сюда message id или id пользователя которому придет сообщение
    :argument text: Передай сюда текст который выведется при попадании в меню"""
    
    # !ВНИМАНИЕ!  -->  Нужно как то стандартизировать ввод и обработку ID для случая когда дается собственный и чужой ID
    if type(message_arg) == type(123): USER_ID = message_arg
    else: USER_ID = message_arg.from_user.id
        
    markup = types.ReplyKeyboardMarkup(resize_keyboard=True)
    users_dict[USER_ID]["Homerun"] = "Old"

    if USER_LOC == "Main":
        addition_button = types.KeyboardButton("Credits")
        look_queue_button = types.KeyboardButton("Посмотреть очередь")
        
        if users_dict[USER_ID]["InQueueStatus"] == False:
            get_in_queue_button = types.KeyboardButton("Встать в очередь")
            markup.add(get_in_queue_button, look_queue_button, addition_button)
            
        else:
            get_in_queue_button = types.KeyboardButton("Выйти из очереди")
            change_name_button = types.KeyboardButton("Изменить имя")
            markup.add(get_in_queue_button, look_queue_button, addition_button, change_name_button)

    elif USER_LOC == "Admin_Main":
        users_dict[USER_ID]["Location"] = "Admin_Main"
        look_queue_button = types.KeyboardButton("Посмотреть очередь")
        debug_button = types.KeyboardButton("Отладка")
        next_button = types.KeyboardButton("Следующий")
        markup.add(debug_button, next_button, look_queue_button)

    elif USER_LOC == "Registration_Cab":
        return_button = types.KeyboardButton("Вернуться назад")
        confirm_registration_button = types.KeyboardButton("Подтвердить")
        markup.add(return_button, confirm_registration_button)

    elif USER_LOC == "Passport_Office":
        return_button = types.KeyboardButton("Вернуться назад")
        confirm_registration_button = types.KeyboardButton("Подтвердить")
        markup.add(return_button, confirm_registration_button)

    Bot.send_message(USER_ID, text=text, reply_markup=markup)


def make_queue(QUEUE):
    """Переводит список в очередь для отображения

    :argument QUEUE: Список"""
    i = 0
    output = ""
    for position in QUEUE:
        i += 1
        output += str(i) + ". " + str(position).split("_")[0] + "\n"
    return output


def start_registration(USER_ID):
    """Начинает регистрацю в очереди

    :argument USER_ID: ID пользователя"""
    if users_dict[USER_ID]["Name"] == "":
        users_dict[USER_ID]["Location"] = "Registration_Cab"
        users_dict[USER_ID]["ExecuteStatus"] = True
        #ПЕРЕПИСАТЬ
        initialize_menu(USER_ID, "Пришли свою фамилию. Когда будешь готов, жми на кнопку подтвердить", users_dict[USER_ID]["Location"])

    else:
        welcome_in_queue(USER_ID)
        users_dict[USER_ID]["Location"] = "Main"
        initialize_menu(USER_ID, "Я тебя помню! Добро пожаловать в очередь.\nСнова", users_dict[USER_ID]["Location"])


def compile_debug():
    """Составляет отчет по пользователям и их атрибутам

    :return: строка для вывода"""
    debug_str = ""
    for user in users_dict.keys():
        debug_str += "ID: " + str(user) + "\n"
        for param in users_dict[user].keys():
            debug_str += str(param) + ": " + str(users_dict[user][param]) + "\n"
        debug_str += "------------------------\n"
    return debug_str


def leave_queue(USER_ID, status="Самоотвод"):
    """Исключает из очереди пользователя

    :argument USER_ID: ID пользователя"""
    if QUEUE:
        if (users_dict[USER_ID]["Name"] + "_" + str(USER_ID)) in QUEUE:
            users_dict[USER_ID]["InQueueStatus"] = False
            QUEUE.remove(users_dict[USER_ID]["Name"] + "_" + str(USER_ID))
            if status == "Вызов":
                users_dict[USER_ID]["Location"] = "Main"
                initialize_menu(USER_ID, compile_user_tag(USER_ID) + "\n"
                                          "Теперь твоя очередь! Защити Лабу! GO! GO! GO!", users_dict[USER_ID]["Location"])


def change_name(USER_ID):
    if users_dict[USER_ID]["Name"]:
        users_dict[USER_ID]["Location"] = "Passport_Office"
        users_dict[USER_ID]["NameChangeStatus"] = True
        #ПЕРЕПИСАТЬ
        initialize_menu(USER_ID, "Пришли новое имя. Когда будешь готов, жми на кнопку подтвердить", users_dict[USER_ID]["Location"])


def get_index_from_id(USER_ID):
    Index = QUEUE.index(users_dict[USER_ID]["Name"] + "_" + str(USER_ID))
    return Index


def compile_user_tag(USER_ID):
    user_tag = users_dict[USER_ID]["Tag"]
    if user_tag == None: user_tag = "Товарищ!!"
    else: user_tag = "@" + user_tag
    return user_tag


def send_queue_status(target_USER_ID):
    target_index = get_index_from_id(target_USER_ID)
    if target_index == 0: Bot.send_message(target_USER_ID, "Готовься. Ты следующий!")
    else: Bot.send_message(target_USER_ID, "Уже ОЧЕНЬ скоро!\nПеред тобой " + str(target_index) + " человек!")

        
def spam_queue_for_all():
    for target in QUEUE:
        target_id = int(target.split("_")[1])
        send_queue_status(target_id)

        
def fix_menu(USER_ID, USER_LOC):
    """{"Name": "",
     "ExecuteStatus": False,
     "NameChangeStatus": False,
     "Cash": "",
     "InQueueStatus": False,
     "Admin": False,
     "Tag": user_tag,
     "Location": "Main",
     "Homerun": "New"}"""
    # Если вдруг что-то пошло не так из за интернет соединение, перезапуска бота, юзер жмет сюда и все чинится. Halelujah!!
    if USER_LOC == "Admin_Main":
        users_dict[USER_ID]["ExecuteStatus"] = False
        users_dict[USER_ID]["NameChangeStatus"] = False
        users_dict[USER_ID]["Admin"] = True

    elif USER_LOC == "Main":
        users_dict[USER_ID]["ExecuteStatus"] = False
        users_dict[USER_ID]["NameChangeStatus"] = False
        users_dict[USER_ID]["Admin"] = False

    elif USER_LOC == "Registration_Cab":
        users_dict[USER_ID]["ExecuteStatus"] = True
        users_dict[USER_ID]["NameChangeStatus"] = False
        users_dict[USER_ID]["Admin"] = False

    elif USER_LOC == "Passport_Office":
        users_dict[USER_ID]["ExecuteStatus"] = False
        users_dict[USER_ID]["NameChangeStatus"] = True
        users_dict[USER_ID]["Admin"] = False

    initialize_menu(USER_ID, "Ну вроде поправил", USER_LOC)


# Задача
# Рассылка сообщений при
#       1 Выходе из очереди
#       2 При вызове следующего в очереди
# Для этого при каждом изменении (удалении из) очереди инициализировать функцию рассылки сообщений.
# Функция рассылки должна давать разный результат в зависимости
# от относительной позиции юзера в очереди.
# Должны быть предусмотрены следующие выводы:
#       Если человек следующий сообщать об этом и о том кого вызвали сейчас.
#       Иначе рассылать сообщение в котором сообщается кол-во человек перед ним (Без пинга)
#
#       Переписать функцию инициализации меню
# Locations:
# Admin_Main
# Main
# Registration_Cab
# Passport_Office


#----------------> ОБРАБОТКА СООБЩЕНИЙ <---------------------
@Bot.message_handler(content_types=['text'])

def func(message):
    global users_dict
    with open('data.pickle', 'rb') as f: users_dict = pickle.load(f)

    USER_ID = message.from_user.id
    initialize_user(USER_ID, message)
    USER_LOC = users_dict[USER_ID]["Location"]

    if message.text == "/report_bug": fix_menu(USER_ID, USER_LOC)
    else:
        if users_dict[USER_ID]["ExecuteStatus"] == True:
            if (message.text == "Подтвердить") and (USER_LOC == "Registration_Cab"):
                if users_dict[USER_ID]["Cash"] == "": Bot.send_message(USER_ID, text="ОБЯЗАТЕЛЬНО пришли мне свою фамилию!")
                # !ВНИМАНИЕ!  -->  переписать условное выражение покороче
                elif (len(users_dict[USER_ID]["Cash"].split()) != 1) or (len(users_dict[USER_ID]["Cash"].split("_")) != 1) or users_dict[USER_ID]["Cash"] in BANNED_NAMES:
                    Bot.send_message(USER_ID, text="Недопустимое имя! Просто введи свою ФАМИЛИЮ!")

                else:
                    welcome_in_queue(USER_ID)
                    users_dict[USER_ID]["Location"] = "Main"
                    initialize_menu(message, "Хорошо! Ты в очереди!", users_dict[USER_ID]["Location"])

            elif (message.text == "Вернуться назад") and (USER_LOC == "Registration_Cab"):
                users_dict[USER_ID]["ExecuteStatus"] = False
                users_dict[USER_ID]["Cash"] = ""
                users_dict[USER_ID]["Location"] = "Main"
                initialize_menu(message, "Что, снова?", users_dict[USER_ID]["Location"])

            else:
                users_dict[USER_ID]["Cash"] = message.text

        elif users_dict[USER_ID]["NameChangeStatus"] == True:
            if (message.text == "Подтвердить") and (USER_LOC == "Passport_Office"):
                if users_dict[USER_ID]["Cash"] == "": Bot.send_message(USER_ID, text="Кто из нас хочет сменить имя? Пришли хоть что-то!")
                # !ВНИМАНИЕ!  -->  переписать условное выражение покороче
                elif (len(users_dict[USER_ID]["Cash"].split()) != 1) or (len(users_dict[USER_ID]["Cash"].split("_")) != 1) or users_dict[USER_ID]["Cash"] in BANNED_NAMES:
                    Bot.send_message(USER_ID, text="Недопустимое имя! Имя это одно слово.")

                else:
                    INDEX = get_index_from_id(USER_ID)
                    users_dict[USER_ID]["Name"] = users_dict[USER_ID]["Cash"]
                    users_dict[USER_ID]["Cash"] = ""
                    QUEUE[INDEX] = users_dict[USER_ID]["Name"] + "_" + str(USER_ID)
                    users_dict[USER_ID]["Location"] = "Main"
                    initialize_menu(message, "Теперь ты " + users_dict[USER_ID]["Name"] + ". Наслаждайся", users_dict[USER_ID]["Location"])
                    users_dict[USER_ID]["NameChangeStatus"] = False

            elif (message.text == "Вернуться назад") and (USER_LOC == "Passport_Office"):
                users_dict[USER_ID]["NameChangeStatus"] = False
                users_dict[USER_ID]["Cash"] = ""
                users_dict[USER_ID]["Location"] = "Main"
                initialize_menu(message, "Что, снова?", users_dict[USER_ID]["Location"])

            else: users_dict[USER_ID]["Cash"] = message.text

        else:
            if users_dict[USER_ID]["Admin"] == True:
                if (message.text == "Следующий") and (USER_LOC == "Admin_Main"):
                    if QUEUE:
                        target_id = int(QUEUE[0].split("_")[1])
                        target_name = QUEUE[0].split("_")[0]
                        target_tag = compile_user_tag(target_id)

                        if "@" in target_tag: Bot.send_message(USER_ID, text="На очереди " + target_name + "\n" + target_tag)
                        else: Bot.send_message(USER_ID, text="На очереди " + target_name)

                        leave_queue(target_id, "Вызов")
                        spam_queue_for_all()

                    else: Bot.send_message(USER_ID, text="Похоже в очереди СОВСЕМ пусто...")

                elif (message.text == "Отладка") and (USER_LOC == "Admin_Main"): Bot.send_message(USER_ID, text=compile_debug())
                elif (message.text == "Посмотреть очередь") and (USER_LOC == "Admin_Main"):
                    if QUEUE: Bot.send_message(USER_ID, text=make_queue(QUEUE))
                    elif users_dict[USER_ID]["Admin"] == True: Bot.send_message(USER_ID, text="Похоже в очереди пусто...")

                elif (message.text == "DQDDI"):
                    users_dict[USER_ID]["Admin"] = False
                    users_dict[USER_ID]["Location"] = "Main"
                    initialize_menu(message, "Теперь ты чернь. Встань в очередь!", users_dict[USER_ID]["Location"])

            elif (message.text == "Встать в очередь") and (USER_LOC == "Main"):
                if users_dict[USER_ID]["InQueueStatus"] == False: start_registration(USER_ID)
                elif users_dict[USER_ID]["InQueueStatus"] == True: Bot.send_message(USER_ID, text="Ты УЖЕ в очереди!")

            elif (message.text == "Посмотреть очередь") and (USER_LOC == "Main"):
                if QUEUE: Bot.send_message(USER_ID, text=make_queue(QUEUE))
                else: Bot.send_message(USER_ID, text="Будь ПЕРВЫМ!\nВстань в ОЧЕРЕДЬ на лабу!\nУ тебя ПОЛУЧИТСЯ!!\nВерь в себя!")

            elif (message.text == "Credits") and (USER_LOC == "Main"):
                Bot.send_photo(USER_ID, open(r"C:\Users\heave\PycharmProjects\pythonProject1\media\Lain_new_year.jpg", "rb"))
                Bot.send_message(USER_ID, "Made by Cyberteam 2011\nMain programmer: Row FB")

            elif (message.text == "Выйти из очереди") and (USER_LOC == "Main"):
                leave_queue(USER_ID)
                users_dict[USER_ID]["Location"] = "Main"
                initialize_menu(message, "Вы вывшли из очереди", users_dict[USER_ID]["Location"])
                spam_queue_for_all()

            elif (message.text == "Изменить имя") and (USER_LOC == "Main"):
                change_name(USER_ID)

            elif (message.text == "Red_sun_in_the_sky") and (USER_LOC == "Main"):
                users_dict[USER_ID]["Admin"] = True
                if users_dict[USER_ID]["InQueueStatus"] == True:
                    leave_queue(USER_ID)
                    spam_queue_for_all()
                Bot.send_photo(USER_ID, open(r"C:\Users\heave\PycharmProjects\pythonProject1\media\hell.jpg", "rb"))
                users_dict[USER_ID]["Location"] = "Admin_Main"
                initialize_menu(message, "Вы в режиме администратора!\n"
                                         "Для работы с очередьюью воспользуйтесь кнопками\n\n"
                                         "В режиме Администратора вы не можете состоять в очереди (если вы состояли в очереди, то уже нет XD)\n"
                                         "для выхода из режима администрирования введите слово входа наоборот", users_dict[USER_ID]["Location"])

            elif (message.text == "IVALTEK_NEW") and (USER_LOC == "Main") and (users_dict[USER_ID]["InQueueStatus"] == False) and (users_dict[USER_ID]["Admin"] == False):
                welcome_king(USER_ID)
                users_dict[USER_ID]["Location"] = "Main"
                initialize_menu(message, "Kiss me goodbye\n"
                                         "Love's memory\n"
                                         "Follow your heart\n"
                                         "And find your destiny\n\n"
                                         "Добро пожаловть мастер!", users_dict[USER_ID]["Location"])
                Bot.send_photo(USER_ID, open(r"C:\Users\heave\PycharmProjects\pythonProject1\media\Lain_sunset.jpg", "rb"))
                Bot.send_audio(USER_ID, open(r"C:\Users\heave\PycharmProjects\pythonProject1\audio\IVALTEK_OP_VER.mp3", "rb"))

    with open('DATA.pickle', 'wb') as f: pickle.dump(users_dict, f)


Bot.polling(none_stop=True, interval=0)


test_meaaage_param = {
    'content_type': 'text',
    'id': 2262,
    'message_id': 2262,
     'from_user': {'id': 700717719,
                   'is_bot': False,
                   'first_name': 'Югослав',
                   'username': 'bruh_IIDX',
                   'last_name': None,
                   'language_code': 'ru',
                   'can_join_groups': None,
                   'can_read_all_group_messages': None,
                   'supports_inline_queries': None,
                   'is_premium': None,
                   'added_to_attachment_menu': None},
     'date': 1664971378,
     'chat': {'id': 700717719,
              'type': 'private',
              'title': None,
              'username': 'bruh_IIDX',
              'first_name': 'Югослав',
              'last_name': None,
              'photo': None,
              'bio': None,
              'join_to_send_messages': None,
              'join_by_request': None,
              'has_private_forwards': None,
              'has_restricted_voice_and_video_messages': None,
              'description': None,
              'invite_link': None,
              'pinned_message': None,
              'permissions': None,
              'slow_mode_delay': None,
              'message_auto_delete_time': None,
              'has_protected_content': None,
              'sticker_set_name': None,
              'can_set_sticker_set': None,
              'linked_chat_id': None,
              'location': None},
     'sender_chat': None,
     'forward_from': None,
     'forward_from_chat': None,
     'forward_from_message_id': None,
     'forward_signature': None,
     'forward_sender_name': None,
     'forward_date': None,
     'is_automatic_forward': None,
     'reply_to_message': None,
     'via_bot': None,
     'edit_date': None,
     'has_protected_content': None,
     'media_group_id': None,
     'author_signature': None,
     'text': 'Отладка',
     'entities': None,
     'caption_entities': None,
     'audio': None,
     'document': None,
     'photo': None,
     'sticker': None,
     'video': None,
     'video_note': None,
     'voice': None,
     'caption': None,
     'contact': None,
     'location': None,
     'venue': None,
     'animation': None,
     'dice': None,
     'new_chat_member': None,
     'new_chat_members': None,
     'left_chat_member': None,
     'new_chat_title': None,
     'new_chat_photo': None,
     'delete_chat_photo': None,
     'group_chat_created': None,
     'supergroup_chat_created': None,
     'channel_chat_created': None,
     'migrate_to_chat_id': None,
     'migrate_from_chat_id': None,
     'pinned_message': None,
     'invoice': None,
     'successful_payment': None,
     'connected_website': None,
     'reply_markup': None,
     'json': {'message_id': 2262,
              'from': {'id': 700717719,
                       'is_bot': False,
                       'first_name': 'Югослав',
                       'username': 'bruh_IIDX',
                       'language_code': 'ru'},
              'chat': {'id': 700717719,
                       'first_name': 'Югослав',
                       'username': 'bruh_IIDX',
                       'type': 'private'},
              'date': 1664971378,
              'text': 'Отладка'}
     }





