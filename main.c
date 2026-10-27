#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[30];
    int secret_num, guess = 0;
    int attempts;
    int max_attempts = 7;
    int game1_att = 0, game2_att = 0, game3_att = 0;
    int choice = 0;
    int sorted1, sorted2, sorted3; // Эрэмбэлэлт хийх хувьсагчид
    int temp, i;
    float percent;

    srand(time(0));

    printf("=== ТОМЬЁОЛОЛТТОЙ ТОО ТААХ ТОГЛООМ ===\n");

    // Өгөгдөл авах: нэр (scanf)
    printf("Нэрээ оруулна уу: ");
    scanf("%s", name);
    printf("Сайн уу, %s!\n", name);

    // Оролтын шалгалт ба үндсэн давталт (do-while)
    do {
        printf("\nЦэс сонгоно уу:\n");
        printf("1. Тоглоом эхлүүлэх\n");
        printf("2. Гарах\n");
        printf("Таны сонголт: ");

        if (scanf("%d", &choice) != 1) {
            printf("Буруу оролт! Зөвхөн тоо оруулна уу.\n");
            while (getchar() != '\n'); // Буфер цэвэрлэх
            continue;
        }

        // Оролтын шалгалт (1-2-оос өөр утга орвол дахин асууна)
        if (choice < 1 || choice > 2) {
            printf("Алдаа: Сонголт 1 эсвэл 2 байх ёстой. Дахин оролдоно уу.\n");
            continue;
        }

        if (choice == 1) {
            // Санамсаргүй тоо үүсгэх (1-100)
            secret_num = (rand() % 100) + 1;
            attempts = 0;

            printf("\n--- Шинэ тоглоом эхэллээ (1-100 хооронд) ---\n");

            while (attempts < max_attempts) {
                printf("Оролдлого %d/%d. Таны таамаг: ", attempts + 1, max_attempts);

                // Оролтын шалгалт (хүрээнээс гадуур утга шалгах)
                if (scanf("%d", &guess) != 1) {
                    printf("Буруу оролт! Бүхэл тоо оруулна уу.\n");
                    while (getchar() != '\n');
                    continue;
                }

                if (guess < 1 || guess > 100) {
                    printf("Анхааруулга: 1 болон 100 хооронд байх ёстой!\n");
                    continue;
                }

                attempts++;

                // Нөхцөл шалгах (else-if)
                if (guess == secret_num) {
                    printf("Баяр хүргэе! Та зөв таалаа. Зарцуулсан оролдлого: %d\n", attempts);
                    break;
                } else if (guess > secret_num) {
                    printf("Миний санасан тоо арай БАГА байна.\n");
                } else {
                    printf("Миний санасан тоо арай ИХ байна.\n");
                }
            }

            if (attempts >= max_attempts && guess != secret_num) {
                printf("Уучлаарай, таны 7 оролдлого дууслаа! Санасан тоо %d байлаа.\n", secret_num);
                attempts = max_attempts; // дээд хязгаараар бүртгэх
            }

            // Өмнөх тоглолтуудын үр дүнг шилжүүлэх
            game3_att = game2_att;
            game2_att = game1_att;
            game1_att = attempts;

            // 3 тоглолт дууссан бол үр дүнг эрэмбэлж хүснэгт хэвлэх
            if (game1_att > 0 && game2_att > 0 && game3_att > 0) {
                // 3 утгыг эрэмбэлэх логик (if ашиглан багаас их рүү)
                sorted1 = game1_att;
                sorted2 = game2_att;
                sorted3 = game3_att;

                if (sorted1 > sorted2) { temp = sorted1; sorted1 = sorted2; sorted2 = temp; }
                if (sorted1 > sorted3) { temp = sorted1; sorted1 = sorted3; sorted3 = temp; }
                if (sorted2 > sorted3) { temp = sorted2; sorted2 = sorted3; sorted3 = temp; }

                printf("\nТоглогч: %s\n", name);
                printf("========================================\n");
                printf("%-15s %-12s %-10s\n", "Тоглолтын дугаар", "Оролдлого", "Үр дүнгийн ангилал");
                printf("========================================\n");
                printf("%-15s %-12d %-10s\n", "Тоглолт 1", game1_att, game1_att <= 4 ? "Сайн" : "Дунд");
                printf("%-15s %-12d %-10s\n", "Тоглолт 2", game2_att, game2_att <= 4 ? "Сайн" : "Дунд");
                printf("%-15s %-12d %-10s\n", "Тоглолт 3", game3_att, game3_att <= 4 ? "Сайн" : "Дунд");
                printf("========================================\n");
                printf("Эрэмбэлэгдсэн оролдлогууд (багаас их рүү): %d, %d, %d\n", sorted1, sorted2, sorted3);

                // Давталтаар 7 мөр бүхий хүснэгт: оролдлого бүрийн оноо
                printf("\n--- Оноо тооцох хүснэгт ---\n");
                printf("%-10s %-8s %6s\n", "Oroldlogo", "Angilal", "Huvi");
                for (i = 1; i <= max_attempts; i++) {
                    percent = (max_attempts + 1 - i) * 100.0 / max_attempts;
                    printf("%-10d %-8s %6.2f\n", i, i <= 4 ? "Sain" : "Dund", percent);
                }
            }

        } else if (choice == 2) {
            printf("Тоглоомоос гарлаа. Баярлалаа!\n");
            break;
        }

    } while (choice != 2);

    return 0;
}