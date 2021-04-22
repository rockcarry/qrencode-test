#include <stdlib.h>
#include <stdio.h>
#include "qrencode.h"

int main(int argc, char *argv[])
{
    QRcode *qr = NULL;
    unsigned char *data;
    int x, y;

    if (argc < 2) {
        printf("usage: qrencode [STRING]\n");
        return 0;
    }

    qr = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    printf("version: %d\n", qr->version);
    printf("width  : %d\n", qr->width  );
    printf("\n");

    data = qr->data;
    for (y=0; y<qr->width; y++) {
        for (x=0; x<qr->width; x++) {
            printf("%c ", (*data & 1) ? '#' : ' ');
            data++;
        }
        printf("\n");
    }

    if (qr) QRcode_free(qr);
    return 0;
}

