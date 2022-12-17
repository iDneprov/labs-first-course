import telebot
import requests
from bs4 import BeautifulSoup
import time
import csv


#Токен моего бота
TOKEN = '5964387331:AAHY2tzeq9_pNUOCySLHeIhW7lXpvvcSe9k'
bot = telebot.TeleBot(TOKEN)

#Реакция бота на команду start
@bot.message_handler(commands=['start'])
def send_welcome(message):
    bot.send_message(message.chat.id, "Let's go parse dollar value!")


#Реакция бота на какое-то текстовое сообщение
@bot.message_handler(content_types=['text'])
def parsing(message):

    #Для более "простого" кода создаю класс, парсящий данные
    class Dollar_Value_Checker:
            #url страницы
            url = 'https://www.google.com/search?q=rehc+ljkkfhf&oq=rehc&aqs=chrome.0.69i59j69i57j0i10i131i433i512l4j0i10i433i512j0i10i131i433i512l3.1219j0j7&sourceid=chrome&ie=UTF-8'
            
            #Заголовки, чтобы сделать вид, что запросы делает человек, а не робот
            headers = {"User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.128 Safari/537.36"}
            
            #Разница в курсах
            difference = 0.01

            #Текущее значение курса
            cur_dol_val = 0
            
            #Присвоим cor_dol_val значение курса на данный момент
            def __init__(self):
                self.cur_dol_val = self.parse_dol()
            
            #Парсинг
            def parse_dol(self):

                #Код страницы на html
                page = requests.get(self.url, headers=self.headers)

                #Делаем объект soup'a, чтобы библиотека могла с ним работать
                soup_page = BeautifulSoup(page.text, 'html.parser')

                #Найдём, где лежит значение курса рубля
                dol_value_text = soup_page.findAll("span", {"class": "DFlfde", "class":"SwHCTb"})

                #Преобразуем его из текста в число
                dol_value_float = float(dol_value_text[0].text.replace(',', '.'))

                return dol_value_float
            #Проверка на изменение
            def change_check(self, interval):
                current_dol = self.parse_dol()
                if (current_dol > self.cur_dol_val + self.difference):
                    bot.send_message(message.chat.id, "Value is up")
                    print(time.strftime(" %c:   UP:", time.localtime()), self.parse_dol())

                elif (current_dol < self.cur_dol_val - self.difference):
                    bot.send_message(message.chat.id, "Value is down")
                    print(time.strftime(" %c:   DOWN:", time.localtime()), self.parse_dol())

                else:
                    bot.send_message(message.chat.id, "Didn't change :\ ")
                    print(time.strftime(" %c:   DIDN'T CHANGED:", time.localtime()), self.parse_dol())
                
                time.sleep(interval)
                return [time.strftime(" %c", time.localtime()), self.parse_dol()]
                #self.change_check(interval)
    
    if message.text == "go":
        current_dol = Dollar_Value_Checker()
        with open("dol_values.csv", "w") as file:
            writer = csv.writer(file)
            writer.writerow(
                ["Дата", "Курс"]
            )

        bot.send_message(message.chat.id, "Okay")

        #Зададим параметры времени работы
        worktime = 0.5 * 60 
        interval = 15
        currenttime = 0
        
        while (worktime > currenttime):
            with open("dol_values.csv", "a") as file:
                writer = csv.writer(file)
                writer.writerow(
                    current_dol.change_check(interval)
                )
            currenttime += interval
        

bot.infinity_polling()
