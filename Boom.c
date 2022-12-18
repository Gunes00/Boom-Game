#include <stdio.h>

#define SATIR 6
#define SUTUN 7

// Prototipler
void tahtaOlustur(char tahta[SATIR][SUTUN]);
int ilerle(char tahta[SATIR][SUTUN], int sutun, char taslar);
int kazandimi(char tahta[SATIR][SUTUN]);

int main()
{
    char tahta[SATIR][SUTUN]; // Oyun tahtası

    // Oyun başlangıcında tahtayı boşaltır
    for (int i = 0; i < SATIR; i++)
    {
        for (int j = 0; j < SUTUN; j++)
        {
            tahta[i][j] = ' ';
        }
    }

    int sira = 0;
    int sutun;
    int satir;
    while (1)
    {
        // Oyun tahtasını oluşturur
        tahtaOlustur(tahta);

        // Sütun seçimi alınır
        printf("Oyuncu %d, bir sutun sec: ", sira + 1);
        scanf("%d", &sutun);

        // Doğruluk kontrolü
        satir = ilerle(tahta, sutun, sira == 0 ? 'X' : 'O');
        if (satir == -1)
        {
            printf("Geçersiz hamle. Tekrar deneyin.\n");
            continue;
        }

        // Oyuncu x kazandı mı ?
        if (kazandimi(tahta))
        {
            printf("Oyuncu %d kazandı! BOOM !!\n", sira + 1);
            break;
        }

        // Sıra değiştir
        sira = (sira + 1) % 2;
    }

    return 0;
}

// Her tur bitiminde oyun tahtasını günceller
void tahtaOlustur(char tahta[SATIR][SUTUN])
{
    printf("\n");

    printf("  ");
    for (int i = 0; i < SUTUN; i++)
    {
        printf(" %d", i + 1);
    }
    printf("\n");

    for (int i = 0; i < SATIR; i++)
    {
        printf("|");
        for (int j = 0; j < SUTUN; j++)
        {
            printf(" %c", tahta[i][j]);
        }
        printf(" |\n");
    }

    printf(" ");
    for (int i = 0; i < SUTUN + 2; i++)
    {
        printf("-");
    }
    printf("\n");
}

int ilerle(char tahta[SATIR][SUTUN], int sutun, char taslar)
{
    // Sütunun dolup dolmadığı kontrol edilir
    if (tahta[0][sutun] != ' ')
    {
        return -1;
    }

    for (int i = SATIR - 1; i >= 0; i--)
    {
        if (tahta[i][sutun] == ' ')
        {
            tahta[i][sutun] = taslar;
            return i;
        }
    }

    return -1;
}

int kazandimi(char tahta[SATIR][SUTUN])
{
    // Yatay dizilimde kazandı mı ?
    for (int i = 0; i < SATIR; i++)
    {
        for (int j = 0; j < SUTUN - 3; j++)
        {
            if (tahta[i][j] == tahta[i][j+1] && tahta[i][j] == tahta[i][j+2] && tahta[i][j] == tahta[i][j+3] && tahta[i][j] != ' ')
            {
                return 1;
            }
        }
    }

    // Dikey dizilimde kazandı mı ?
    for (int i = 0; i < SATIR - 3; i++)
    {
        for (int j = 0; j < SUTUN; j++)
        {
            if (tahta[i][j] == tahta[i+1][j] && tahta[i][j] == tahta[i+2][j] && tahta[i][j] == tahta[i+3][j] && tahta[i][j] != ' ')
            {
                return 1;
            }
        }
    }

    // Çapraz dizilimde kazandı mı ?
    for (int i = 0; i < SATIR - 3; i++)
    {
        for (int j = 0; j < SUTUN - 3; j++)
        {
            if (tahta[i][j] == tahta[i+1][j+1] && tahta[i][j] == tahta[i+2][j+2] && tahta[i][j] == tahta[i+3][j+3] && tahta[i][j] != ' ')
            {
                return 1;
            }
        }
    }
    for (int i = 3; i < SATIR; i++)
    {
        for (int j = 0; j < SUTUN - 3; j++)
        {
            if (tahta[i][j] == tahta[i-1][j+1] && tahta[i][j] == tahta[i-2][j+2] && tahta[i][j] == tahta[i-3][j+3] && tahta[i][j] != ' ')
            {
                return 1;
            }
        }
    }

    return 0;
}
