public class Main {
    public static void main(String[]args) {
        Dataset ds = new Dataset();
        ds.generateWeights(ds.weights);
        ds.learn();
    }
}
