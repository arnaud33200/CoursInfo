using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {    
            Console.WriteLine("HELLO BIBU !!!");

            #region Code ajouté
            int[] entiers = { 1, 2, 3 };
            for (int i = 0; i < entiers.Length; i++)
                Console.WriteLine(i);

            List<string> lachaine = new List<string>();
            lachaine.Add("janvier");
            lachaine.Add("fevrier");
            foreach (string s in lachaine)
                Console.WriteLine(s);
            #endregion
            lachaine.Add("mars");
            lachaine.Add("sdqsdq");

            Console.Read();
        }
    }
}