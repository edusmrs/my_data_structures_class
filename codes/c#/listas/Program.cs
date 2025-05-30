List<int> lista = new List<int>();
Random gerador = new Random();
for (int i = 0; i < 10; i++)
{
    lista.Add(gerador.Next(1, 100));
}

lista.Sort();

for(int j = 0; j < lista.Count; j++)
{
    Console.WriteLine(lista[j]);
}

foreach (var b in lista)
{
    Console.WriteLine(b);
}

var k = lista.GetEnumerator();
while (k.MoveNext())
{
    Console.WriteLine(k.Current);
}
