from pybrain3.supervised.trainers import BackpropTrainer
import dataset
import network
trainer = BackpropTrainer(network.network, dataset.ds, learningrate=0.1, verbose=True, momentum=0.1)
trainer.trainEpochs(1300)
letters = ["A", "B", "C", "D", "E", "F", "H", "I", "J", "K", "L", "Ł", "M", "O", "P", "Q", "R", "S", "T", "U"]
inp = dataset.ds['input']
for i in range(20):
    print("For letter", letters[i], "output return:")
    temp = network.network.activate(inp[i])
    for j in range(20):
        print("Output for letter", letters[j], "are:", temp[j])
    print("\n")
