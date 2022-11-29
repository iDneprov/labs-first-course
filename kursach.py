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

allnumbers = []
for i in range(1023, 9877):
    f = True
    for j in range(4):
        if str(i).count(str(i)[j]) > 1:
            f = False
    if f:
        allnumbers.append(str(i))
array_of_possible_answers = allnumbers.copy()

question1 = first_question()
print(question1)
bulls = int(input('bulls: '))
cows = int(input('cows: '))
message1 = Message(question1, bulls, cows)
array_of_possible_answers = apdate_array_of_possible_answers(array_of_possible_answers, message1)

if message1.bulls + message1.cows == 4:
    if len(array_of_possible_answers) == 1:
        print(array_of_possible_answers[0])
else:
    question2 = second_question(question1)
    print(question2)
    bulls = int(input('bulls: '))
    cows = int(input('cows: '))
    message2 = Message(question2, bulls, cows)
    array_of_possible_answers = apdate_array_of_possible_answers(array_of_possible_answers, message2)

while True:
    if len(array_of_possible_answers) == 1:
        print(array_of_possible_answers[0])
        break
    quality_of_questions = [0] * len(allnumbers)
    for i in range(len(allnumbers)):
        quality_of_questions[i] = aestimation(allnumbers[i])
    question = allnumbers[quality_of_questions.index(max(quality_of_questions))]
    print(question)
    bulls = int(input('bulls: '))
    cows = int(input('cows: '))
    message = Message(str(question), bulls, cows)
    array_of_possible_answers = apdate_array_of_possible_answers(array_of_possible_answers, message)

