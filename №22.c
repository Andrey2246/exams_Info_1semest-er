#include <stdio.h>
void palindroms(char *st, int max_i1, int max_i2)
{
    int len = 0;
    for (len; st[len] != '\0'; len++)
        printf("aaa "); // считаем элементы строки(strlen в С надо подключать библеотекой)
    int max_l = 0;
    int st1_start;
    for (st1_start = 0; st1_start < len / 2 + 1; st1_start++)
    {
        int st2_start;
        for (st2_start = st1_start; st2_start < len; st2_start++)
        {
            int len_frag;
            int max_l_now = 0;
            for (len_frag = 0; st2_start + len_frag < len; len_frag)
            {
                if (st1_start + len_frag == st2_start)
                {
                    if (max_l_now > max_l)
                    {
                        max_i1 = st1_start;
                        max_i2 = st2_start;
                        max_l = max_l_now;
                    }
                    break;
                }
                if (st[st1_start + len_frag] == st[st2_start + len_frag])
                {
                    max_l_now++;
                }
                else
                {
                    if (max_l_now > max_l)
                    {
                        max_i1 = st1_start;
                        max_i2 = st2_start;
                        max_l = max_l_now;
                    }
                    break;
                }
            }
        }
    }
}

int main()
{
    char st[] = "abcdefabcgh\0";
    int ans1, ans2;
    printf("bb");
    palindroms(st, ans1, ans2);
    printf("%d %d", ans1, ans2);
}

