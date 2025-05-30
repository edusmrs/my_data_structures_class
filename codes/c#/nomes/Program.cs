List<string> listanomes = new List<string>();
string opcao;
string nome;

do{
  Console.WriteLine("Digite um nome completo: ");
  nome = Console.ReadLine();
  nome = nome.ToUpper();

  if(!listanomes.Contains(nome)){
    listanomes.Add(nome);
  }else{
    Console.WriteLine("Nome já cadastrado");
  }
  
  Console.WriteLine("1 - Continuar | 2 - Sair");
  opcao = Console.ReadLine();

}while(opcao != "2");

listanomes.Sort();

Console.WriteLine("A lista contém os seguintes nomes: " + listanomes.Count);

foreach(string n in listanomes){
  Console.WriteLine(n);
}