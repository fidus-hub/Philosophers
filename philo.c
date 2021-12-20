#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void    *routine( )
{
    printf("test1\n");
    sleep(3);
    printf("ending thread\n");
}

//int main()
//{
//   pthread_t   thread;
//    int i = 0;

//    while (i < 5)
//    {
//        pthread_create(&thread, NULL, &routine, NULL);
//        printf("WWWWWW\n");
//        i++;
//    }
    // pthread_join(thread, NULL);
//}

int main(int argc, char **argv)
{
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        return 1;
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
        return 2;
    if (pthread_join(t1, NULL) != 0)
        return 3;
    if (pthread_join(t2, NULL) != 0)
        return 4;
    return 0; 
}
