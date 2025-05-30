List<string> listanomes = new List<string>();
List<int> glicemia = new List<int>();
Random gerador = new Random();

string opcao;
string nome;
double media = 0;
double mediana = 0;
double moda = 0;

do{

  Console.WriteLine("Digite um nome completo: ");
  nome = Console.ReadLine();
  nome = nome.ToUpper();

  if(!listanomes.Contains(nome)){
    listanomes.Add(nome);
    glicemia.Add(gerador.Next(50, 240));
  }else{
    Console.WriteLine("Nome já cadastrado");
  }
  
  Console.WriteLine("1 - Continuar | 2 - Sair");
  opcao = Console.ReadLine();


}while(opcao != "2");

listanomes.Sort();
glicemia.Sort();

foreach(int g in glicemia){
  Console.WriteLine(g);
}

media = glicemia.Average();
Console.WriteLine("A média da glicemia é: " + media);

if(glicemia.Count % 2 == 0){
  mediana = (glicemia[glicemia.Count / 2] + glicemia[(glicemia.Count / 2) - 1]) / 2;
  Console.WriteLine("A mediana da glicemia é: " + mediana);
}else{
  mediana = glicemia[glicemia.Count / 2];
  Console.WriteLine("A mediana da glicemia é: " + mediana);
}

Dictionary<int, int> frequencia = new Dictionary<int, int>();
foreach (int num in glicemia)
{
    if (frequencia.ContainsKey(num))
        frequencia[num]++;
    else
        frequencia[num] = 1;
}

int maxFreq = frequencia.Values.Max();
List<int> moda = frequencia.Where(x => x.Value == maxFreq).Select(x => x.Key).ToList();




