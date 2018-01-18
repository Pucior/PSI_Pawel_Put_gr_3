from pybrain3.supervised.trainers import BackpropTrainer
import network
import dataset
trainer = BackpropTrainer(network.network, dataset.ds, learningrate=0.8, verbose=True)
trainer.trainEpochs(8)
letters = ["A", "B", "C", "D", "E", "F", "H", "M", "P", "Q", "a", "b", "c", "d", "e", "f", "h", "m", "p", "q"]
inp = dataset.ds['input']
errorComparator = 0.900
for i in range(20):
    temp = network.network.activate(inp[i])
    print("For letter", letters[i], "precision is", temp[0])
    if errorComparator < temp:
        print("Letter", letters[i], "is capital letter")
    else:
        print("Letter", letters[i], "is small letter")
print("\n")
