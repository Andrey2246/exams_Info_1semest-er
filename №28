//28.  Заменить в строке все целые константы из любого количества цифр соответствующим повторением следующего за ними символа
//(например "abc5xacb15y" - " abcxxxxxacbyyyyyyyyyyyyyyy ").
#include <stdio.h>
void unpack(char *st, char *ans){
    int i = 0;
    int ansi = 0;
    int n, n1;
    while(st[i] != '\n'){
        n = st[i] - '0'; // коды цифр идут по порядку => чтобы найти число надо из его кода вычесть код символа '0'
        if (n > 0 and n < 10){ // если нашли цифру,
            n1 = st[i+1] - '0';
            while (n1 > 0 and n1 < 10){ // смотрим, если ли после нее цифры и объединяем их в число n
                n = n * 10 + n1;
                i++;
                n1 = st[i+1] - '0';
            }
            for (int j = 0; j < n - 1;j++){ // записываем в выходную строку следующий элемент входной строки n - 1 раз (еще 1 раз будет потом, просто как число)
                ans[ansi] = st[i+1];
                ansi++;
            }
            i++;
        }
        ans[ansi] = st[i]; // если не нашли число, просто переписываем букву в выходную строку
        ansi++;
        i++;
    }
    ans[ansi] = '\0';

}
int main(){
    char ans[255];
    char st[] = "ab13cdef\n";
    unpack(st, ans);
    printf("%s\n", ans);
    char st1[] = "abc5xacb15y\n";
    unpack(st1, ans);
    printf("%s\n", ans);
    char st2[] = "SU5lZWRIZWxw\n";
    unpack(st2, ans);
    printf("%s\n", ans);
}
