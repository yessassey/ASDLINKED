#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Cetak isi list
void printList(Node* head) {
    cout << "[";
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->data;
        if (cur->next) cout << " -> ";
    }
    cout << "]\n";
}

// Bebaskan memori
void freeList(Node*& head) {
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;

    // ------- Inisialisasi list awal -------
    cout << "Masukkan jumlah elemen awal list: ";
    int n;
    cin >> n;

    if (!cin || n < 0) {
        cout << "Input tidak valid.\n";
        return 0;
    }

    // Input elemen awal (jika ada)
    for (int i = 0; i < n; i++) {
        cout << "Masukkan nilai node ke-" << (i + 1) << ": ";
        int val;
        cin >> val;

        Node* newNode = new Node(val);

        // Insert di akhir untuk membentuk list awal
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = newNode;
        }
    }

    cout << "\nList awal: ";
    printList(head);
    // ---------------------------------------

    // -------- Insert di AWAL (BEGINNING) --------
    int x;
    cout << "Masukkan nilai yang ingin di-insert ke awal: ";
    cin >> x;

    if (!cin) {
        cout << "Input tidak valid.\n";
        freeList(head);
        return 0;
    }

    // Operasi inti: Insert di awal
    Node* newNode = new Node(x);
    newNode->next = head;  // head lama jadi next
    head = newNode;        // node baru jadi head
    // ----------------------------------------

    cout << "List setelah insert di awal: ";
    printList(head);

    freeList(head);
    return 0;
}