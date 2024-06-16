#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pasien {
    int id_pasien;
    char nama[100];
    char tanggal_lahir[11];
    char alamat[200];
    char nomor_telepon[15];
    struct Pasien* next;
} Pasien;

Pasien* head_pasien = NULL;
int pasienCount = 0;

void tambahPasien(char nama[], char tanggal_lahir[], char alamat[], char nomor_telepon[]) {
    Pasien* new_pasien = (Pasien*)malloc(sizeof(Pasien));
    new_pasien->id_pasien = pasienCount + 1;
    strcpy(new_pasien->nama, nama);
    strcpy(new_pasien->tanggal_lahir, tanggal_lahir);
    strcpy(new_pasien->alamat, alamat);
    strcpy(new_pasien->nomor_telepon, nomor_telepon);
    new_pasien->next = head_pasien;
    head_pasien = new_pasien;
    pasienCount++;
}

void cariPasien(char nama[]) {
    Pasien* current = head_pasien;
    while (current != NULL) {
        if (strstr(current->nama, nama) != NULL) {
            printf("ID: %d, Nama: %s, Tanggal Lahir: %s, Alamat: %s, Nomor Telepon: %s\n",
                   current->id_pasien, current->nama, current->tanggal_lahir,
                   current->alamat, current->nomor_telepon);
        }
        current = current->next;
    }
}

void ubahPasien(int id_pasien, char nama[], char tanggal_lahir[], char alamat[], char nomor_telepon[]) {
    Pasien* current = head_pasien;
    while (current != NULL) {
        if (current->id_pasien == id_pasien) {
            strcpy(current->nama, nama);
            strcpy(current->tanggal_lahir, tanggal_lahir);
            strcpy(current->alamat, alamat);
            strcpy(current->nomor_telepon, nomor_telepon);
            printf("Data pasien dengan ID %d berhasil diubah.\n", id_pasien);
            return;
        }
        current = current->next;
    }
    printf("Pasien dengan ID %d tidak ditemukan.\n", id_pasien);
}

void hapusPasien(int id_pasien) {
    Pasien* current = head_pasien;
    Pasien* previous = NULL;
    while (current != NULL) {
        if (current->id_pasien == id_pasien) {
            if (previous == NULL) {
                head_pasien = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            pasienCount--;
            printf("Pasien dengan ID %d berhasil dihapus.\n", id_pasien);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Pasien dengan ID %d tidak ditemukan.\n", id_pasien);
}

int main() {
    return 0;
}
