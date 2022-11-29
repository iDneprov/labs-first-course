import random

LEN = 4
ALL_POSSIBLE_ANSWERS = [[0, 0], [0, 1], [0, 2], [0, 3], [0, 4], [1, 0], [1, 1], [1, 2], [1, 3], [2, 0], [2, 1], [2, 2],
                        [3, 0]]  # все возможные комбинации количества быков и коров в числе относительно загаданного
class Message(object):
    def __init__(self, number, bulls, cows):
        self.number = number
        self.bulls = bulls
        self.cows = cows

def apdate_array_of_possible_answers(array_of_possible_answers, new_message):
    new_array_of_possible_answers = []
    for i in range(len(array_of_possible_answers)):
        bulls = 0  # быки
        cows = 0
        for j in range(LEN):
            if new_message.number[j] == array_of_possible_answers[i][j]:
                bulls += 1
            elif new_message.number[j] in array_of_possible_answers[i]:
                cows += 1
        if bulls == new_message.bulls and cows == new_message.cows:
            new_array_of_possible_answers.append(array_of_possible_answers[i])
    return new_array_of_possible_answers

def delta_number_of_possible_answers(array_of_possible_answers, supposed_message):
    new_array_of_possible_answers = []
    for i in range(len(array_of_possible_answers)):
        bulls = 0  # быки
        cows = 0
        for j in range(LEN):
            if supposed_message.number[j] == array_of_possible_answers[i][j]:
                bulls += 1
            elif supposed_message.number[j] in array_of_possible_answers[i]:
                cows += 1
        if bulls == supposed_message.bulls and cows == supposed_message.cows:
            new_array_of_possible_answers.append(array_of_possible_answers[i])
    if len(new_array_of_possible_answers) == 0:
        return -1
    else:
        return len(array_of_possible_answers) - len(new_array_of_possible_answers)

def mean(deltas):  # среднее арифметическое
    summa = sum(deltas)
    return (summa / len(deltas))

def aestimation(number):  # оценка вероятного влияния посылки на множество чисел, предположительно являющихся ответом
    deltas = []
    for i in ALL_POSSIBLE_ANSWERS:
        supposed_message = Message(number, i[0], i[1])
        deltas.append(delta_number_of_possible_answers(array_of_possible_answers, supposed_message))
    return mean(deltas)  # float

def first_question():
    num = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    question = ''
    for i in range(4):
        if i == 0:
            question = question + random.choice(num[1:])
        else:
            question = question + random.choice(num)
        num.remove(question[i])
    return (question)

def second_question(question1):
    num = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    for i in question1:
        num.remove(i)
    question = ''
    for i in range(4):
        if i == 0 and '0' in num:
            question = question + random.choice(num[1:])
        else:
            question = question + random.choice(num)
        num.remove(question[i])
    return (question)

def Grigorys_num():
    nums = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    number = ''
    for i in range(4):
        if i == 0:
            number = number + random.choice(nums[1:])
        else:
            number = number + random.choice(nums)
        nums.remove(number[i])
    print('I made a number: ' + number)
    return number

def Grigory(question, NUMBER):
    bulls = cows = 0
    for i in range(4):
        if question[i] == NUMBER[i]:
            bulls += 1
        elif question[i] in NUMBER:
            cows += 1
    if bulls + cows == 0:
        print('None')
    else:
        print('Bulls: ', bulls, ' Cows: ', cows)
    return (bulls, cows)

allnumbers = []
for i in range(1023, 9877):
    f = True
    for j in range(4):
        if str(i).count(str(i)[j]) > 1:
            f = False
    if f:
        allnumbers.append(str(i))

game = 0
total_questions = 0
while True:
    game += 1
    print('game', game)
    array_of_possible_answers = allnumbers.copy()
    NUMBER = Grigorys_num()
    question1 = first_question()
    print(question1)
    bulls, cows = Grigory(question1, NUMBER)
    message1 = Message(question1, bulls, cows)
    array_of_possible_answers = apdate_array_of_possible_answers(array_of_possible_answers, message1)
    end = False
    num_of_questions = 1
    if message1.bulls + message1.cows == 4:
        if len(array_of_possible_answers) == 1:
            print('This is it:  ', array_of_possible_answers[0])
            print('---------------------------')
            end = True
    else:
        question2 = second_question(question1)
        print(question2)
        bulls, cows = Grigory(question2, NUMBER)
        message2 = Message(question2, bulls, cows)
        array_of_possible_answers = apdate_array_of_possible_answers(array_of_possible_answers, message2)
        num_of_questions += 1
    while not end:
        if len(array_of_possible_answers) == 1:
            print('This is it:  ', array_of_possible_answers[0])
            print('---------------------------')
            break
        quality_of_questions = [0] * len(allnumbers)
        for i in range(len(allnumbers)):
            quality_of_questions[i] = aestimation(allnumbers[i])
        question = allnumbers[quality_of_questions.index(max(quality_of_questions))]
        print(question)
        num_of_questions += 1
        bulls, cows = Grigory(question, NUMBER)
        message = Message(str(question), bulls, cows)
        array_of_possible_answers = apdate_array_of_possible_answers(array_of_possible_answers, message)
    total_questions += num_of_questions
    print('Statistics:  games:', game, '  average_number_of_questions:', total_questions / game)

