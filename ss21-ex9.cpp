#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DishMenu {
    int id;
    char name[100];
    float price;
};

struct DishMenu menu[100];
int menuSize = 7;

void inraDishMenu() {
    printf("Menu cua chung toi o day:\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d. Name: %s, Price: %.1f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

void themDishMenu() {
    if (menuSize >= 100) {
        printf("Menu do an da du, ko the them cac mon an khac o ben ngoai dc nua roi, ban thong cam nha..\n");
        return;
    }

    struct DishMenu newDishMenu;
    printf("Nhap ID mon an: ");
    scanf("%d", &newDishMenu.id);
    getchar();
    printf("Nhap ten mon an Tiem Banh Mi PLinh : ");
    fgets(newDishMenu.name, 100, stdin);
    newDishMenu.name[strcspn(newDishMenu.name, "\n")] = '\0';
    printf("Nhap gia mon an Tiem Banh Mi PLinh : ");
    scanf("%f", &newDishMenu.price);

    menu[menuSize++] = newDishMenu;
    printf("Mon an  Tiem Banh Mi PLinh  da duoc them vao menu.\n");
}

void suaDishMenu() {
    int index;
    printf("Nhap vi tri mon an Tiem Banh Mi PLinh  can sua (0-%d): ", menuSize - 1);
    scanf("%d", &index);

    if (index < 0 || index >= menuSize) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    getchar();
    printf("Nhap ten do an moi Tiem Banh Mi PLinh  : ");
    fgets(menu[index].name, 100, stdin);
    menu[index].name[strcspn(menu[index].name, "\n")] = '\0';
    printf("Nhap gia moi Tiem Banh Mi PLinh : ");
    scanf("%f", &menu[index].price);
    printf("Mon an Tiem Banh Mi PLinh  da duoc cap nhat.\n");
}

void xoaDishMenu() {
    int index;
    printf("Nhap vi tri mon an Tiem Banh Mi PLinh  can xoa (0-%d): ", menuSize - 1);
    scanf("%d", &index);

    if (index < 0 || index >= menuSize) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = index; i < menuSize - 1; i++) {
        menu[i] = menu[i + 1];
    }
    menuSize--;
    printf("Mon an Tiem Banh Mi PLinh  da duoc xoa.\n");
}

int compareDescending(const void *a, const void *b) {
    return ((struct DishMenu *)b)->price - ((struct DishMenu *)a)->price;
}

void linearSearch() {
    char searchName[100];
    getchar();
    printf("Nhap ten mon an can tim Tiem Banh Mi PLinh : ");
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < menuSize; i++) {
        if (strcmp(menu[i].name, searchName) == 0) {
            printf("Tim thay: Id:%d. Name: %s, Price: %.1f\n", menu[i].id, menu[i].name, menu[i].price);
            return;
        }
    }
    printf("ban thong cam , hien khong tim thay mon an trong menu  Tiem Banh Mi PLinh .\n");
}

void showMenu() {
    printf("\n--- Menu ---\n");
    printf("1. In menu mon an Tiem Banh mi Plinh \n");
    printf("2. Them mon an Tiem Banh mi Plinh \n");
    printf("3. Sua mon an Tiem Banh mi Plinh \n");
    printf("4. Xoa mon an Tiem Banh mi Plinh \n");
    printf("5. Sap xep theo gia mon an Tiem Banh mi Plinh  giam dan\n");
    printf("6. Tim kiem mon an Tiem Banh mi Plinh \n");
    printf("7. Thoat chuong trinh cua Tiem Banh Mi Plinh \n");
}

void xulyMenuChoice(int choice) {
    switch (choice) {
        case 1:
            inraDishMenu();
            break;
        case 2:
            themDishMenu();
            break;
        case 3:
            suaDishMenu();
            break;
        case 4:
            xoaDishMenu();
            break;
        case 5:
            qsort(menu, menuSize, sizeof(struct DishMenu), compareDescending);
            printf("Menu Tiem Banh mi Plinh cac mon an da sap xep.\n");
            break;
        case 6:
            linearSearch();
            break;
        case 7:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
    }
}

int main() {
    menu[0] = (struct DishMenu){1, "Banh Mi Pate", 15.0 };
    menu[1] = (struct DishMenu){2, "Banh Mi Xa Xiu", 20.0};
    menu[2] = (struct DishMenu){3, "Banh Mi Thit", 10.0};
    menu[3] = (struct DishMenu){4, "Banh Mi Thit Nuong", 40.0};
    menu[4] = (struct DishMenu){5, "Banh Mi Cha", 23.0};
    menu[5] = (struct DishMenu){6, "Banh Mi Bo Sot Vang", 50.0};
    menu[6] = (struct DishMenu){7, "Banh Mi Bo Sua", 10.0};

    int choice;
    do {
         showMenu();
        printf("hay chon cac chuc nang o ben trong menu cua Tiem Banh Mi PLinh chung to nha !!!");
        printf("=)) \n ");
        scanf("%d", &choice);
        xulyMenuChoice(choice);
    } while (choice != 7);

    return 0;
}
