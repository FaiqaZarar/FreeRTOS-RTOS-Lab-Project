#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "mult_task.h"

/* Priority for multiplication task */
#define MULT_TASK_PRIORITY ( tskIDLE_PRIORITY + 1 )

/* Function prototype */
void vMultiplicationTask( void * pvParameters );

/* Helper function to create the task, call this from main_blinky() */
void createMultiplicationTask( void )
{
    xTaskCreate(
        vMultiplicationTask,  // Task function
        "Multiplier",         // Task name
        configMINIMAL_STACK_SIZE,  // Stack size
        NULL,                 // Parameters
        MULT_TASK_PRIORITY,   // Priority
        NULL                  // Task handle not needed
    );
}

/* Task function */
void vMultiplicationTask( void * pvParameters )
{
    (void) pvParameters;

    uint32_t a = 2;
    uint32_t b = 3;
    uint32_t result;

    for( ;; )
    {
        result = a * b;
        printf("Multiplication: %u * %u = %u\r\n", a, b, result);

        /* Update values (optional: simple demo) */
        a++;
        b++;

        vTaskDelay(pdMS_TO_TICKS(1000));  // Delay 1 second
    }
}
