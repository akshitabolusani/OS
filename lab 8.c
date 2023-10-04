#include <pthread.h>
#include <stdio.h>

void* thread_code(void* param) {
    int id = (int)param;
    printf("Start thread %i\n", id);
    return (void*)id;
}

int main() {
    pthread_t thread[10];
    int return_value[10];
    pthread_attr_t attributes;
    
    
    pthread_attr_init(&attributes);
    
    
    for (int i = 0; i < 10; i++) {
        pthread_create(&thread[i], &attributes, &thread_code, (void*)i);
    }
    
    
    for (int i = 0; i < 10; i++) {
        pthread_join(thread[i], (void**)&return_value[i]);
        printf("End thread %i, returned %i\n", i, return_value[i]);
    }
    

    pthread_attr_destroy(&attributes);
    
    return 0;
}
