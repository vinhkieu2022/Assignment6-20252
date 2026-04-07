#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 100
#define MAXLEN 200
int field_no;
int numeric;
void get_field(const char *line, int field_no, char *out) {
    int current = 0; // field hien tai
    int i = 0; // duyet line
    int j = 0; // ghi vao out
    while (line[i] != '0') {
        // bo qua khoang trang
        while (line[i] == ' ' || line[i] == '\t')
            i++;
        if (line[i] == '\0') {
          break; 
        }
        current++;
        j = 0;
        while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0') {
            if (current == field_no) {
                out[j++] = line[i]; // copy dữ liệu
            }
            i++;
        }
        if (current == field_no) {
            out[j] = '\0'; //ketthuc som;
            return;
        } 
    }
    out[0] = '\0';
} 
// ===== SO SÁNH FIELD =====
int compare_field(const char *a, const char *b) {
    if (numeric) {
        int x = atoi(a);
        int y = atoi(b);

        if (x < y) return -1;
        if (x > y) return 1;
        return 0;
    } else {
        return strcmp(a, b);
    }
}
// ===== SO SÁNH 2 DÒNG =====
int compare_lines(const void *p1, const void *p2) {
    char *line1 = *(char **)p1;
    char *line2 = *(char **)p2;

    char f1[100], f2[100];

    get_field(line1, field_no, f1);
    get_field(line2, field_no, f2);

    return compare_field(f1, f2);
}
int main() {
    char *lines[MAXLINES];
    char temp[MAXLEN]; // nhap tam 1 dong
    int n = 0;
    printf("Nhap field : ");
    scanf("%d", &field_no);

    printf("So hay chu? (1 = so, 0 = chu): ");
    scanf("%d", &numeric);

    getchar(); 

    printf("\nNhap cac dong:\n");
    while (n < MAXLINES) {
         fgets(temp, MAXLEN, stdin);
        if (temp[0] == '\n'){
            // neu ko nhap gi ca -> ket thuc 
            break;
        } else {
            // xoa ki tu \n
            temp[strcspn(temp, "\n")] = '\0';
            // cap phat bo nho
            lines[n] = (char *)malloc(strlen(temp) + 1);
            // copy gcc
            strcpy(lines[n], temp);
            n++;
        }
    }
    qsort(lines, n, sizeof(char *), compare_lines);
    printf("\nket qua:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}