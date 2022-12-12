//22.  Найти в строке два одинаковых фрагмента, не содержащих пробелы и имеющих максимальную длину и возвратить индексы их начала
#include <stdio.h>
void palindroms(char *st, int *max_i1, int *max_i2)
{
    int len = 0;
    for (len; st[len] != '\0'; len++);// считаем элементы строки(strlen в С надо подключать библеотекой)
    int max_l = 0; // максиум
    int st1_start;//индекс начала первого проверяемого фрагмента
    for (st1_start = 0; st1_start < len / 2 + 1; st1_start++)// до половины строки, т.к. одинаковые фрагменты не могут пересекаться
    {
        int st2_start;//индекс начала второго проверяемого фрагмента
        for (st2_start = st1_start + 1; st2_start < len; st2_start++) // опять же, фрагменты не пересекаются
        {
            int len_frag;//предполагаемая длина фрагмента
            for (len_frag = 0; st2_start + len_frag < len; len_frag++)//проверяем на равенство пока не дойдем до конца строки, либо не найдем различие
            {
                if (st1_start + len_frag == st2_start or st1_start == ' ')// если фрагменты пересекаются или нашли пробел, выходим из цикла
                {
                    if (len_frag > max_l)
                    {
                        *max_i1 = st1_start;
                        *max_i2 = st2_start;
                        max_l = len_frag;
                    }
                    break;
                }
                if (st[st1_start + len_frag] == st[st2_start + len_frag]); //все ок пока фрагменты совпадают
                else                                                       // а как только перестали, запомнили максимальную длину и идем дальше
                {
                    if (len_frag > max_l)
                    {
                        *max_i1 = st1_start;
                        *max_i2 = st2_start;
                        max_l = len_frag;
                    }
                    break;
                }
            }
        }
    }
}

int main()
{
    char st[] = "abcdef abcgh";
    int ans1 = -1, ans2 = -1;
    palindroms(st, &ans1, &ans2);
    printf("%d %d\n", ans1, ans2);
    char st1[] = "cebcrblrnyucnapedzepbdikehppxrefwsfrcgrslltgkfyofr";
    ans1 = -1;
    ans2 = -1;
    palindroms(st1, &ans1, &ans2);
    printf("%d %d", ans1, ans2);
}

