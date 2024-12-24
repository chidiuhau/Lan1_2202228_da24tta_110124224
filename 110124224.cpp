#include <iostream>
using namespace std;

// Ham nhap gia tri cua mang
void nhapMang(float a[], int k) {
    cout << "Nhap " << k << " gia tri cho mang: \n";
    for (int i = 0; i < k; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

// Ham xuat gia tri cua mang
void xuatMang(float a[], int k) {
    cout << "Mang da nhap: \n";
    for (int i = 0; i < k; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Ham dem cac phan tu trong mang
int demPhanTuDuong(float a[], int k) {
    int count = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] > 0) {
            count++;
        }
    }
    return count;
}

// Ham tinh cac tong gia tri trong mang
float tinhTong(float a[], int k) {
    float sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    return sum;
}

//Ham kiem tra mang co ton tai gia tri x cho truoc hay khong
bool kiemTraTonTai(float a[], int k, float x) {
    for (int i = 0; i < k; i++) {
        if (a[i] == x) {
            return true;
        }
    }
    return false;
}

// Ham in ra man hinh vi tri cua cac phan tu lon nhat va nho nhat trong mang
void inViTriMinMax(float a[], int k) {
    if (k == 0) return;
    
    float max = a[0], min = a[0];
    int maxIdx = 0, minIdx = 0;

    for (int i = 1; i < k; i++) {
        if (a[i] > max) {
            max = a[i];
            maxIdx = i;
        }
        if (a[i] < min) {
            min = a[i];
            minIdx = i;
        }
    }

    cout << "Phan tu lon nhat la a[" << maxIdx << "] = " << max << endl;
    cout << "Phan tu nho nhat la a[" << minIdx << "] = " << min << endl;
}

// Ham sap xep cac gia tri trong mang tang dan
void sapXepMang(float a[], int k) {
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (a[i] > a[j]) {
                // Hoan doi
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int k;
    
    // Nhap gia tri k tu ban phim
    cout << "Nhap so phan tu k (k < 30): ";
    cin >> k;

    // Kiem tra k co lap lai khong
    if (k <= 0 || k >= 30) {
        cout << "So phan tu k phai > 0 va < 30!" << endl;
        return 0;
    }

    float a[k]; // Mang so thuc

    // Nhap mang
    nhapMang(a, k);

    // Xuat mang 
    xuatMang(a, k);

    // Ðem phan tu duong
    cout << "So luong phan tu duong: " << demPhanTuDuong(a, k) << endl;

    // Tinh tong cac phan tu
    cout << "Tong cac phan tu trong mang: " << tinhTong(a, k) << endl;

    // Kiem tra phan tu co ton tai khong
    float x;
    cout << "Nhap gia tri x can kiem tra: ";
    cin >> x;
    if (kiemTraTonTai(a, k, x)) {
        cout << "Gia tri " << x << " ton tai trong mang." << endl;
    } else {
        cout << "Gia tri " << x << " khong ton tai trong mang." << endl;
    }

    // In vi tri cac phan tu lon nhat va nho nhat
    inViTriMinMax(a, k);

    // Sap xep mang theo thu tu tang dan
    sapXepMang(a, k);

    // Xuat mang sau khi sap xep
    cout << "Mang sau khi sap xep: \n";
    xuatMang(a, k);

    return 0;
}

