#include <stdio.h>
#include <string.h>
int strend (char s[], char t[]) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    if (len_t > len_s) {
        return 0;
    } else {
        for (int i = 0; i < len_t; i++) {
            if (t[i] != s[i+ len_s - len_t]) {
                return 0;
            }
        }
        return 1;
    }   
}
int main() {
    char s[100];
    char t[100];

    printf("Nhap chuoi s: ");
    fgets(s, sizeof(s), stdin);

    printf("Nhap chuoi t: ");
    fgets(t, sizeof(t), stdin);

    //xóa ký tự '\n' do fgets thêm vào
    s[strcspn(s, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';

    int k = strend(s, t);
    printf("Ket qua: %d\n", k);

    return 0;
}