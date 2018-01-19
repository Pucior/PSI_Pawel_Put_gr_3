public class Main {
    public static void main(String[]args) {
        double learningrate = 0.01;
        double damagedAOutput = 1;
        int lettersToLearning = 20;
        Dataset ds = new Dataset();
        ds.generateWeights(ds.weights);
        for(int k = 0; k < 100; k++) {
            for (int i = 0; i < lettersToLearning; i++) {
                for (int j = 0; j < 35; j++) {
                    ds.weights[j] = ds.weights[j] + learningrate * ds.letters[i][j] * ds.outputs[i];
                }
                for (int j = 0; j < 35; j++){
                    ds.outputs[i] = ds.weights[j] * ds.letters[i][j];
                }
            }
            if (k % 5 == 0)
                lettersToLearning --;
        }
        for (int j = 0; j < 35; j++) {
            System.out.println("For " + j + " weight output is: " + ds.weights[j]);
        }
        System.out.println();
        for (int j = 0; j < 20; j++) {
            System.out.println("For " + ds.lettersToOutput[j] + " letter output is: " + ds.outputs[j]);
        }
    }
}