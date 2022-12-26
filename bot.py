from settings import *

logging.basicConfig(level=logging.INFO)

bot = Bot(token=config.bot_token.get_secret_value())
storage = MemoryStorage()
dp = Dispatcher(bot=bot, storage=storage)

storage = MemoryStorage()
dp = Dispatcher(bot, storage=storage)


class Form(StatesGroup):
    text = State()
    time = State()
    status = State()


@dp.message_handler(commands='start')
async def cmd_start(message: types.Message):
    await Form.text.set()
    await message.reply("Привет, " + message.from_user.full_name + '! ' + 'О чем я тебе должен буду напомнить?')


@dp.message_handler(state='*', commands='cancel')
@dp.message_handler(Text(equals='cancel', ignore_case=True), state='*')
async def cancel_handler(message: types.Message, state: FSMContext):
    current_state = await state.get_state()
    if current_state is None:
        return
    logging.info('Cancelling state %r', current_state)
    await state.finish()
    await message.reply('Отменено.', reply_markup=types.ReplyKeyboardRemove())


@dp.message_handler(state=Form.text)
async def process_text(message: types.Message, state: FSMContext):
    async with state.proxy() as data:
        data['text'] = message.text

    await Form.next()
    await message.reply("Через сколько напомнить (чч:мм)?")


@dp.message_handler(lambda message: message.text, state=Form.time)
async def process_time(message: types.Message, state: FSMContext):
    await Form.next()
    await state.update_data(time=message.text)
    markup = types.ReplyKeyboardMarkup(resize_keyboard=True, selective=True)
    markup.add("Высокая", "Средняя")
    markup.add("Низкая")
    await message.reply("Выбери степень важности этого дела", reply_markup=markup)


@dp.message_handler(state=Form.status)
async def process_status(message: types.Message, state: FSMContext):
    async with state.proxy() as data:
        data['status'] = message.text
        markup = types.ReplyKeyboardRemove()
        if data['status'] == 'Высокая':
            await bot.send_message(
                message.chat.id,
                md.text(
                    md.text('Вы добавили новое напоминания: ', md.bold(data['text'])),
                    md.text('Через сколько нужно будет напомнить:', md.code(data['time'])),
                    md.text('Степень важности напоминания:', md.bold(data['status'])),
                    sep='\n',
                ),
                reply_markup=markup,
                parse_mode=ParseMode.MARKDOWN,
            )
        if data['status'] == 'Средняя':
            await bot.send_message(
                message.chat.id,
                md.text(
                    md.text('Вы добавили новое напоминания: ', md.bold(data['text'])),
                    md.text('Через сколько нужно будет напомнить:', md.code(data['time'])),
                    md.text('Степень важности напоминания:', data['status']),
                    sep='\n',
                ),
                reply_markup=markup,
                parse_mode=ParseMode.MARKDOWN,
            )
        if data['status'] == 'Низкая':
            await bot.send_message(
                message.chat.id,
                md.text(
                    md.text('Вы добавили новое напоминания: ', data['text']),
                    md.text('Через сколько нужно будет напомнить:', md.code(data['time'])),
                    md.text('Степень важности напоминания:', data['status']),
                    sep='\n',
                ),
                reply_markup=markup,
                parse_mode=ParseMode.MARKDOWN,
            )
        time.sleep(timer(data['time']))
        if data['status'] == 'Высокая':
            await bot.send_message(
                message.chat.id,
                md.text(
                    md.text('Ты просил напомнить: ', data['text']),
                    md.text('Ты очень хотел это сделать!'),
                    sep='\n',
                ),
                reply_markup=markup,
                parse_mode=ParseMode.MARKDOWN,
            )
        if data['status'] == 'Средняя':
            await bot.send_message(
                message.chat.id,
                md.text(
                    md.text('Ты просил напомнить: ', data['text']),
                    md.text('Ты хотел это сделать!'),
                    sep='\n',
                ),
                reply_markup=markup,
                parse_mode=ParseMode.MARKDOWN,
            )
        if data['status'] == 'Низкая':
            await bot.send_message(
                message.chat.id,
                md.text(
                    md.text('Ты просил напомнить: ', data['text']),
                    md.text('Ты планировал это сделать!'),
                    sep='\n',
                ),
                reply_markup=markup,
                parse_mode=ParseMode.MARKDOWN,
            )
    await state.finish()

@dp.message_handler(commands='help')
async def cmd_start(message: types.Message):
    await bot.send_message(message.chat.id, 'Это бот-напоминалка. Введи /start и следуй всем инструкциям, чтобы правильно установить напоминание!')

if __name__ == '__main__':
    executor.start_polling(dp, skip_updates=True)