# Push_swap
# So_Long
<h1 align="center">
Sort stacks
<h4>
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
<hr>
   <ul>
   <li>sa (swap a): Swap the first 2 elements at the top of stack a.</li>
   <li>sb (swap b): Swap the first 2 elements at the top of stack b.</li>
   <li>ss : sa and sb at the same time.</li>
   <li>pa (push a): Take the first element at the top of b and put it at the top of a.</li>
   <li>pb (push b): Take the first element at the top of a and put it at the top of b.</li>
   <li>ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.</li>
   <li>rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.</li>
   <li>rr : ra and rb at the same time.</li>
   <li>rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.</li>
   <li>rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.</li>
   <li>rrr : rra and rrb at the same time.</li>
   

Для сборки основной части использовать команду 
make

Запуск  основной части
./push_swap 7 9 6 0 -434 45 -53 3 -51 


Write a program named checker that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack. If no argument is given, it stops and displays nothing.
• It will then wait and read instructions on the standard input, each instruction will
be followed by ’\n’. Once all the instructions have been read, the program has to
execute them on the stack received as an argument.
• If after executing those instructions, the stack a is actually sorted and the stack b
is empty, then the program must display "OK" followed by a ’\n’ on the standard output.
• In every other case, it must display "KO" followed by a ’\n’ on the standard output.
• In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.

Для сборки бонусной части использовать команду
   <li>make bonus</li>

Запуск бонусной части
   <li>./checker 7 9 6 0 -434 45 -53 3 -51</li>
   <li>pb</li>
   <li>pb</li>
   <li>rb</li>
   <li>pb</li>
   <li>ra</li>
   <li>ra</li>
   <li>ra</li>
   <li>ra</li>
   <li>pb</li>
   <li>pb</li>
   <li>ra</li>
   <li>pb</li>
   <li>ra</li>
   <li>sb</li>
   <li>pa</li>
   <li>sa</li>
   <li>pa</li>
   <li>rra</li>
   <li>pa</li>
   <li>ra</li>
   <li>pa</li>
   <li>ra</li>
   <li>pa</li>
   <li>ra</li>
   <li>pa</li>
   <li>ra</li>
   <li>ra</li>
   <li>^D</li>


Для быстрого подсчета скорости сортировки на 500 элементов
   <li>
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG > result.txt; ./checker $ARG <result.txt; wc -l <result.txt</li>

на 500 элементов сортировка происходит за 4000 - 4500 операций
</h4>
<h3>

Сортировка на количество элементов более 5 происходит так:
1. Стек А делится на 3 равные части, находится минимальное и максимальное значение.
2. В стеке А остается миксимально, минимальное и меньшая треть значений. При этом остальные две трети перекладываются в стек Б так, чтобы снизу были максимальные, а сверху средние значения.
3. В стек Б перекладывается оставшаяся меньшая треть. В стеке А остается минимальное и максимальное значения. Стек А условно отсортирован. Стек Б разделен на 3 части.
4. Для начений из стека Б рекурсивно расчитывается самая дешевая операция для перекладки 1го значения в стек А чтобы стек А всегда был условно-отсортирован. Стек А и стек Б крутятся в обе стороны. Стек Б полностью перекладываем в стек А.
5. крутим стек А чтобы до полной сортировки.
</h3>
