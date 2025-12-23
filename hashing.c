#include <stdio.h>
#include <stdlib.h>

int tsize, hash[10], count = 0;
int Cal_hash(int key)
{
    return (key % tsize);
}

int Cal_Rehash(int key)
{
    return ((key + 1) % tsize);
}

void insert(int key)
{
    int index;
    if (count != tsize)
    {
        index = Cal_hash(key);
        while(hash[index] != -1){
            index = Cal_Rehash(index);
        }
        hash[index] = key;
        count++;

    }
    else{
        printf("\n Table is full");
    }
}

int search(int key){
    int i, index, loc = -1;
    index = Cal_hash(key);
    for(i = 0; i < tsize; i++){
        loc = (index + i) % tsize;
        if(hash[loc] == key){
            return loc;
        }
    }
    return -1;
}

void delete(int key){
    int loc;
    if(count == 0){
        printf("\n Hash table is empty, can't delete");
    }
    else{
        loc = search(key);
        if(loc != -1){
            hash[loc] = -1;
            count--;
            printf("\n Key %d deleted", key);
        }
        else{
            printf("\n Key %d not found", key);
        }
    }   
}

void display(){
    int i;
    printf("\n The element in the Hash table are :\n ");
    for(i = 0; i < tsize; i++){
        printf("\n Element at postion %d: %d\n", i, hash[i]);
    }
}

int main(){
    int key, i, ch, loc;
    printf("\n Enter the size of the hash table: ");
    scanf("%d", &tsize);
    for(i = 0; i < tsize; i++){
        hash[i] = -1;
    }
    while(1){
        printf("\n 1. Insert");
        printf("\n 2. Search");
        printf("\n 3. Delete");
        printf("\n 4. Display");
        printf("\n 5. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("\n Enter the key to be inserted: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("\n Enter the key to be searched: ");
                scanf("%d", &key);
                loc = search(key);
                if(loc != -1){
                    printf("\n Key %d found at location %d", key, loc);
                }
                else{
                    printf("\n Key %d not found", key);
                }
                break;
            case 3:
                printf("\n Enter the key to be deleted: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\n Invalid choice");
        }
    }
    return 0;
}