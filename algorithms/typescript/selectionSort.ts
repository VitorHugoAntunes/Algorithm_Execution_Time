import stringList from '../../data/data.json';
import stringText from '../../data/text.json';

const list2: Number[] = [];

for (let i = 0; i < 200000; i++) {
    list2.push(parseFloat((Math.random() * 100).toFixed(4)))
}

function selectionSort(array: String[] | Number[]) {
    const startTime = performance.now();

    let arraySize = array.length;

    for (let i = 0; i < arraySize; i++) {
        let min = i;
        for (let j = i + 1; j < arraySize; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }

        if (min != i) {
            let aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }

    const endTime = performance.now();

    const elapsedTime = (endTime - startTime) / 1000;

    const result = {
        "Tempo de execução (segundos)": parseFloat(elapsedTime.toFixed(6)),
    };

    console.log("Array ordenado pelo Selection Sort: \n");
    console.table(array);
    console.table(result);
}

console.log("Array inicial: \n");
console.table(stringText);
selectionSort(stringText)