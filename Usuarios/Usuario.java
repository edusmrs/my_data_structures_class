package Usuarios;

import java.util.ArrayList;

public class Usuario {
    String nome;
    String email;
    ArrayList<Usuario> usuarios = new ArrayList<Usuario>();

    public Usuario(String nome) {
        this.nome = this.verificacaoNome(nome);
        this.email = this.gerarEmail();
        usuarios.add(this);
    }

    public String gerarEmail() {
        String[] nomeSplit = this.nome.split(" ");
        String email = "";

        if (!usuarios.isEmpty()) {
            for (Usuario usuario : usuarios) {
                if (usuario.email.equals(nomeSplit[0].toLowerCase() + "." + nomeSplit[1].toLowerCase().charAt(0) + "@ufn.edu.br")) {
                    if (nomeSplit.length >= 3) {
                        if (nomeSplit[2].equals("da") || nomeSplit[2].equals("de") || nomeSplit[2].equals("do") || nomeSplit[2].equals("dos") || nomeSplit[2].equals("das")) {
                            email = nomeSplit[0].toLowerCase() + "." + nomeSplit[3].toLowerCase().charAt(0) + "@ufn.edu.br";
                        } else {
                            email = nomeSplit[0].toLowerCase() + "." + nomeSplit[2].toLowerCase().charAt(0) + "@ufn.edu.br";
                        }
                    } else {
                        email = nomeSplit[0].toLowerCase() + "." + nomeSplit[1].toLowerCase().charAt(1) + "@ufn.edu.br";
                    }
                } else {
                    email = nomeSplit[0].toLowerCase() + "." + nomeSplit[1].toLowerCase().charAt(0) + "@ufn.edu.br";
                }
            }
        }
        return email;
    }

    public String verificacaoNome(String nome) {
        String nomeVerificado = this.nome.toLowerCase();
        for(Usuario usuario : usuarios) {
            if(usuario.nome.equals(nomeVerificado)) {
                return "Nome já cadastrado";
            }
        }
        if (nomeVerificado.split(" ").length >= 2) {
            return nomeVerificado;
        } else {
            return "Nome inválido, digite um nome composto";
        }
    }
}
