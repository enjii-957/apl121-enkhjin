# Псевдокод (Тоо таах тоглоом)

Функц PrintRow(title, att)           // Flowgorithm-ийн дэд алгоритм
    Хэрэв att <= 4 бол
        хэвлэх title, att, "Сайн"
    Үгүй бол
        хэвлэх title, att, "Дунд"

Main:
1.  Эхлэх
2.  maxAttempts = 7, game1Att = game2Att = game3Att = 0, choice = 0
3.  Нэр уншина (scanf / Input name), мэндчилгээ хэвлэнэ
4.  Давталт (do-while choice != 2):
    4.1  Цэс хэвлээд choice уншина
    4.2  Хэрэв choice < 1 ЭСВЭЛ choice > 2 бол -> "Алдаа" хэвлэж, дахин асууна
    4.3  Үгүй бол choice == 1 үед:
         - secretNum = санамсаргүй утга (1-100)
         - attempts = 0, found = 0
         - Давталт (while attempts < 7 БА found == 0):
           - guess уншина
           - guess < 1 ЭСВЭЛ guess > 100 бол анхааруулга хэвлэнэ (оролдлого тоологдохгүй)
           - Үгүй бол attempts = attempts + 1, дараа нь:
             - guess == secretNum бол "Зөв таалаа" хэвлээд found = 1
             - үгүй бол guess > secretNum бол "БАГА"
             - үгүй бол "ИХ"
         - found == 0 бол санасан тоог хэвлэж, attempts = 7
         - game3Att = game2Att; game2Att = game1Att; game1Att = attempts
         - Хэрэв game1Att, game2Att, game3Att бүгд > 0 бол:
           - sorted1, sorted2, sorted3 = game1Att, game2Att, game3Att
           - if ашиглан 3 утгыг багаас их рүү эрэмбэлнэ
           - Хүснэгтийн толгой хэвлэнэ
           - Call PrintRow("Тоглолт 1", game1Att), мөн 2, 3-т
           - Эрэмбэлэгдсэн оролдлогуудыг хэвлэнэ
           - i = 1-ээс 7 хүртэл давтаж: percent = (8 - i) * 100 / 7,
             "Сайн" (i <= 4) эсвэл "Дунд", percent-ийг хүснэгтийн мөрөөр хэвлэнэ
    4.4  Үгүй бол (choice == 2): "Баярлалаа" хэвлэнэ
5.  Төгсгөл