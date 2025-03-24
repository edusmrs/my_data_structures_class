package Usuarios;

import java.util.Scanner;

public class main {
    public static void main(String[] args) {

        Scanner sn = new Scanner(System.in);
        int choice = 0;
        String nome, email;

        do{
            System.out.println("1 - Adicionar nome composto");
            System.out.println("2 - Sair");
            choice = sn.nextInt();
            sn.nextLine();
            switch(choice){
                case 1:
                    System.out.println("Digite o nome do composto: ");
                    nome = sn.nextLine();
                case 2:
                    break;
                default:
                    System.out.println("Opção inválida");
                    break;
            }

        }while(choice != 2);


    }
}
