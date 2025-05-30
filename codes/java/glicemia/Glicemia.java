import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Glicemia{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        String opcao = "";
        String nome = "";

        ArrayList<Integer> glicemia = new ArrayList<Integer>();
        ArrayList<String> nomes = new ArrayList<String>();

        double media = 0;
        double mediana = 0;
        double moda = 0;

        do{
            System.out.println("1: Adicionar nome; 2: Sair");
            opcao = scanner.nextLine();
            System.out.println("Inserir Nome:");
            nome = scanner.nextLine();

            if(nomes.contains(nome)){
                    System.out.println("Nome ja cadastrado");
            }else{
                    nomes.add(nome);
                    glicemia.add(random.nextInt(50,250));
            }

        }while(!"2".equals(opcao));
        nomes.sort(null);
        glicemia.sort(null);

        System.out.print(nomes+"\n");
        System.out.print(glicemia+"\n");

        for(Integer i : glicemia){
            media += i;
        }

        media = media / glicemia.size();

        System.out.println("Media: " + media+"\n");

        if(glicemia.size() % 2 == 0){
            mediana = (glicemia.get(glicemia.size() / 2) + glicemia.get((glicemia.size() / 2) - 1)) / 2;
        }else{
            mediana = glicemia.get(glicemia.size() / 2);
        }

        System.out.println("Mediana: " + mediana);
    }
}