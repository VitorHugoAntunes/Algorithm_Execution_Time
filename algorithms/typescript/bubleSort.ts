import stringList from '../../data/data.json';

const list: Number[] = [];

for (let i = 0; i < 10; i++) {
    list.push(parseFloat((Math.random() * 10).toFixed(2)))
}

let averageTime: Number = 0;

function bubbleSort(array: String[]) {
    const startTime = performance.now();

    for (var i = 0; i < array.length; i++) {

        // Last i elements are already in place  
        for (var j = 0; j < (array.length - i - 1); j++) {

            // Checking if the item at present iteration 
            // is greater than the next iteration
            if (array[j] > array[j + 1]) {

                // If the condition is true
                // then swap them
                var aux = array[j]
                array[j] = array[j + 1]
                array[j + 1] = aux
            }
        }
    }

    const endTime = performance.now();

    const elapsedTime = endTime - startTime;

    const result = {
        "Tempo de execução (ms)": parseFloat(elapsedTime.toFixed(6)),
    };

    // Print the sorted array
    console.log("Array ordenado pelo Bubble Sort: \n");
    console.table(array);
    console.table(result);
}

console.log("Array inicial: \n");
console.table(stringList);
bubbleSort(stringList)