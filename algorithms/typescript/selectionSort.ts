const list2: Number[] = [];

for (let i = 0; i < 10; i++) {
    list2.push(parseFloat((Math.random() * 10).toFixed(2)))
}

function selectionSort(array: Number[]) {
    const startTime = performance.now();

    let arraySize = array.length;

    for (let i = 0; i < arraySize; i++) {
        // Finding the smallest number in the subarray
        let min = i;
        for (let j = i + 1; j < arraySize; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            // Swapping the elements
            let aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }

    const endTime = performance.now();

    const elapsedTime = endTime - startTime;

    const result = {
        "Tempo de execução (ms)": parseFloat(elapsedTime.toFixed(6)),
    };

    console.log("Array ordenado pelo Bubble Sort: \n");
    console.table(array);
    console.table(result);
}

console.log("Array inicial: \n");
console.table(list2);
selectionSort(list2)