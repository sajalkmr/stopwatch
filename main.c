#include <stdio.h>
#include <time.h>

struct stopwatch
{
    time_t start_time;
    double elapsed_time;
};

void start_stopwatch(struct stopwatch *sw)
{
    if (!sw->start_time)
    {
        sw->start_time = time(NULL);
    }
    else
    {
        time_t end_time = time(NULL);
        sw->elapsed_time += difftime(end_time, sw->start_time);
        sw->start_time = 0;
    }
}

void reset_stopwatch(struct stopwatch *sw)
{
    sw->start_time = 0;
    sw->elapsed_time = 0.0;
}

void print_elapsed_time(double elapsed_seconds)
{
    int hours, minutes, seconds;

    hours = (int)elapsed_seconds / 3600;
    elapsed_seconds -= hours * 3600;

    minutes = (int)elapsed_seconds / 60;
    elapsed_seconds -= minutes * 60;

    seconds = (int)elapsed_seconds;

    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}

int main()
{
    struct stopwatch sw = {0};
    int choice;

    while (1)
    {
        printf("1. Start\n");
        printf("2. Stop\n");
        printf("3. Reset\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start_stopwatch(&sw);
            break;
        case 2:
            start_stopwatch(&sw);
            print_elapsed_time(sw.elapsed_time);
            break;
        case 3:
            reset_stopwatch(&sw);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
            break;
        }

        printf("\n");
    }

    return 0;
}