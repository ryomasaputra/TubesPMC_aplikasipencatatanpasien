#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisikan struktur untuk menyimpan data dari CSV
typedef struct {
    int nomor;
    char nama_lengkap[100];
    char alamat[100];
    char kota[50];
    char tempat_lahir[50];
    char tanggal_lahir[20];
    int umur;
    char no_bpjs[30];
    char id_pasien[20];
} DataPasien;

int main() {
    // Nama file CSV dengan path absolut
    const char *filename = "DataPMC20232024_1.csv";

    // Buka file CSV
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Gagal membuka file");
        return EXIT_FAILURE;
    }

    // Membaca header dan mengabaikannya
    char line[512];
    if (fgets(line, sizeof(line), file) == NULL) {
        perror("Gagal membaca header file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Membaca data
    DataPasien data[100]; // Anggap kita hanya memiliki maksimal 100 baris data
    int index = 0;

    // Membuang kolom "No" pada header
    char *token = strtok(line, ",");
    token = strtok(NULL, ","); // Lewati kolom "No"

    // Membaca data
    int nomor = 1; // Nomor awal
    while (fgets(line, sizeof(line), file)) {
        // Hilangkan newline di akhir baris
        line[strcspn(line, "\n")] = 0;

        // Parse data CSV ke dalam struktur
        token = strtok(line, ",");
        strcpy(data[index].nama_lengkap, token);
        
        token = strtok(NULL, ",");
        strcpy(data[index].alamat, token);

        token = strtok(NULL, ",");
        strcpy(data[index].kota, token);

        token = strtok(NULL, ",");
        strcpy(data[index].tempat_lahir, token);

        token = strtok(NULL, ",");
        strcpy(data[index].tanggal_lahir, token);

        token = strtok(NULL, ",");
        data[index].umur = atoi(token);

        token = strtok(NULL, ",");
        strcpy(data[index].no_bpjs, token);

        token = strtok(NULL, ",");
        strcpy(data[index].id_pasien, token);

        data[index].nomor = nomor++; // Atur nomor

        index++;
    }

    fclose(file);

    // Tampilkan data dalam matriks
    printf("No | Nama Lengkap | Alamat | Kota | Tempat Lahir | Tanggal Lahir | Umur | No BPJS | ID Pasien\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < index; i++) {
        printf("%d | %s | %s | %s | %s | %s | %d | %s | %s\n", data[i].nomor,
            data[i].nama_lengkap,
            data[i].alamat,
            data[i].kota,
            data[i].tempat_lahir,
            data[i].tanggal_lahir,
            data[i].umur,
            data[i].no_bpjs,
            data[i].id_pasien);
    }

    return 0;
}

