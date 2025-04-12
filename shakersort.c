

/*void ShakerSort(SingleLinked list)//функция непосредственной сортировки
{
    int left = 0;
    int right = humansize;
    int swapped = 1;

    while (left < right && swapped)
    {
        swapped = 0;
        for (int i = left; i < right; i++)
        {
            if (CompareStructs(HUMAN, i, i + 1) == -flag)
            {
                flypas temp = HUMAN[i];
                HUMAN[i] = HUMAN[i + 1];
                HUMAN[i + 1] = temp;
                swapped = 1;
            }
        }
        right--;

        for (int i = right; i > left; i--)
        {
            if (CompareStructs(HUMAN, i - 1, i) == -flag)
            {
                flypas temp = HUMAN[i - 1];
                HUMAN[i - 1] = HUMAN[i];
                HUMAN[i] = temp;
                swapped = 1;
            }
        }
        left++;
}
}
*/
