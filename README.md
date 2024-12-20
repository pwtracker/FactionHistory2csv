# FactionHistory2csv
Конвертирует файл истории гильдии в CSV таблицу

## Использование
> [!WARNING]
> Клиент игры не умеет правильно сохранять файлы истории: там полно багов и потерь данных. \
> **Настоятельно рекомендуем перед каждой новой конвертацией удалять старые файлы из клиента и прогружать их заново,
> хотя бы раз в 3-5 дней, после объединять их вручную со старыми записями!**

Файлы с историей гильдии расположены в в папке клиента игры: 
```
element\userdata\FactionData\FactionHistoryData
```
**Если они там отстутсвуют, то необходимо зайти в игру и вручную их загрузить, открыв нужное окно истории гильдии.**

Для того, чтобы сконвертировать эти файлы в CSV таблицу, необходимо перетащить файл на нужное вам .exe приложение, 
после в исходной папке создастся .csv файл. Его можно открыть либо в блокноте, либо в Excel.

Приложения и поддерживаемые файлы истории представлены в таблице:

| ПРИЛОЖЕНИЕ               | ПОДДЕРЖИВАЕМЫЕ ФАЙЛЫ  | ЧТО СОДЕРЖИТ                                                        |
|--------------------------|:---------------------:|---------------------------------------------------------------------|
| `DeivdeHistory2csv.exe`  |    `DeivdeHistory`    | История распределения лута                                          |
| `FactionBoard2csv.exe`   |    `FactionBoard`     | Общая история: получение доблести, вступление/выход из гильдии и тд |
| `StorageHistory2csv.exe` |   `StorageHistory`    | История склада гильдии                                              |
| `RawHistory2csv.exe`     | Все вышеперечисленные | Сырой вывод структуры без расшифровки                               |

## Как открыть в Excel
1. Создайте пустой лист.
2. Перейдите на вкладку "Данные" и выберите "Из текстового/CSV-файла".
3. Выберите нужный файл.
4. Укажите "Источник файла" - "Нет" и "Разделитель" - "Табуляция".
5. Нажмите "Загрузить".

## Советы
- Узнать ник игрока (колонка `ИГРОК` или поле `role_id`) можно на [pwobs.com](https://pwobs.com). Например, нужно узнать ник игрока `7852674` на сервере `Саграс`. Ссылка для игроков сервера `Саргас` - https://pwobs.com/sargas/players/, добавляем в конец число `7852674`, получаем https://pwobs.com/sargas/players/7852674.
- Узнать название предмета (`item_id`) можно на [pwdatabase.ru](https://pwdatabase.ru). Для этого достаточно в поиске написать число.
- При объединении таблиц обращать внимание на первую колонку, а не на время.
