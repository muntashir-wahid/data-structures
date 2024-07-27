#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Heap {
private:
    int *data;
    int curr_index;
    int capacity;
    
public:
    Heap(int capacity_val);
    Heap(int capacity_val, int* arr, int size_val);
    ~Heap();
    
    void display();
    void insert(int key);
    
    void get_parent(int key);
    
    void remove();
    
    void display_removed_el();
};

Heap::Heap(int capacity_val)
    : curr_index {0}, capacity {capacity_val + 1} {
        this->data = new int[this->capacity];
        data[0] = 0;
}

Heap::Heap(int capacity_val, int* arr, int size_val) 
    : curr_index {0}, capacity {capacity_val + 1} {
    this->data = new int[this->capacity];
    data[0] = 0;
        
    for(int i = 0; i < size_val; i++) {
        insert(arr[i]);
    }
}

Heap::~Heap() {
    delete [] this->data;
}

void Heap::display() {
    if(curr_index < 1) {
        cout << "Heap is empty!" << endl;
        return;
    }
    
    for(int i = 1; i <= curr_index; i++) {
        cout << this->data[i] << " ";
    }
    
    cout << endl;
}

void Heap::insert(int key) {
    if(this->curr_index + 1 < this->capacity) {
        curr_index++;
        int temp_curr_index = curr_index;

        while(temp_curr_index > 1) {
            int parent_index = temp_curr_index / 2;
            if(data[parent_index] < key) {
                data[temp_curr_index] = data[parent_index];
                temp_curr_index = parent_index;
            } else {
                break;
            }
        }
        
        data[temp_curr_index] = key;
        
        return;
    } 
    
    cout << "Heap is full!" << endl;
    

}


void Heap::get_parent(int key) {
    int parent_index = -1;
    
    for(int i = 1; i <= this->curr_index; i++) {
        if(this->data[i] == key) {
            parent_index = i;
        }
    }
    
    parent_index /= 2;
    
    
    
    cout << "Key " << key << " parent is found at index: " << parent_index << endl;
}

void Heap::remove() {
    if(this->curr_index < 1) {
        cout << "Heap is empty" << endl;
        return;
    }
    
    int removed_el = this->data[1];
    this->data[1] = this->data[this->curr_index--];
    
    int parent_index = 1;
    int left_child;
    
    while(parent_index < this->curr_index) {
        left_child = parent_index * 2;
        
        if(left_child <= this->curr_index) {
            if(left_child + 1 <= this->curr_index && data[left_child + 1] > data[left_child]) {
                left_child++;
            }
            
            if(data[left_child] > data[parent_index]) {
                int temp = data[parent_index];
                
                data[parent_index] = data[left_child];
                data[left_child] = temp;
                
                parent_index = left_child;
                
            } else {
                break;
            }
            
        } else {
            break;
        }
            
        
    }
    
    data[curr_index + 1] = removed_el;
}

void Heap::display_removed_el() {    
    for(int i = this->curr_index + 1; i < this->capacity; i++) {
        cout << this->data[i] << " ";
    }
    
    cout << endl;
}


int main()
{
    int data[] {12, 58, 26, 96, 3, 2, 6, 22, 96, 33, 26, 45, 63, 88, 91};
    Heap max_heap = Heap(15, data, 15);

//    max_heap.display();
    
    for(int i = 0; i < 15;i++) {
        max_heap.remove();
    }
    
//    cout << "\n--- After Heap Sort ---\n" << endl;
    
//    max_heap.display_removed_el();

    
	cout << endl;
	return 0;
}
