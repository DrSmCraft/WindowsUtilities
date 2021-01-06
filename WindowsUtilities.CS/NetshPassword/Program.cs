using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace NetshPassword
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            bool batch_mode = false;
            if (args.Length > 0)
            {
                for (int i = 0; i < args.Length; i++)
                {
                    if (args[i].CompareTo("-h") == 0 || args[i].CompareTo("-?") == 0 ||
                        args[i].CompareTo("--help") == 0)
                    {
                        Console.Out.WriteLine("Netsh Password Utility\nDeveloped by DrSmCraft");
                        Console.Out.WriteLine(
                            "This utility loops through the profiles in \"netsh wlan show profiles\" and displays the password, if there is any\n");
                        Console.Out.WriteLine("-?, --help  : Show this help message\n");
                        Console.Out.WriteLine("-b, --batch : Show batch parsable output\n");
                        return;
                    }
                    else if (args[i].CompareTo("-b") == 0 | args[i].CompareTo("--batch") == 0)
                    {
                        batch_mode = true;
                    }
                    else
                    {
                        Console.Out.WriteLine("ERROR: Unknown argument \"%s\"\nUse -? to see help",
                            args[i]);
                        return;
                    }
                }
            }


            List<string> profileNames = GetWifiProfileNames();

            if (!batch_mode)
            {
                Console.Out.Write("Netsh Password Utility\nDeveloped by DrSmCraft\n\n");

                Console.Out.Write($"{"SSID",-20} | {"Password",20}\n");
                Console.Out.Write("---------------------|---------------------\n");

                foreach (string profileName in profileNames)
                {
                    string password = GetPasswordForWifiProfile(profileName);
                    Console.Out.Write($"{profileName,-20} | {password,20}\n");
                }
            }
            else
            {
                int count = 0;
                foreach (string profileName in profileNames)
                {
                    string password = GetPasswordForWifiProfile(profileName);
                    string comma = count < profileNames.Count - 1 ? "," : "";
                    string output = $"{profileName}:{password}{comma}";
                    
                    Console.Out.Write(output);

                    count++;
                }
            }
        }

        private static List<string> GetWifiProfileNames()
        {
            var proc = new Process
            {
                StartInfo = new ProcessStartInfo
                {
                    FileName = "netsh.exe",
                    Arguments = "wlan show profiles",
                    UseShellExecute = false,
                    RedirectStandardOutput = true,
                    CreateNoWindow = true
                }
            };

            proc.Start();
            string result = proc.StandardOutput.ReadToEnd();
            proc.WaitForExit();
            List<string> profileNames = new List<string>();

            string[] lines = result.Split('\n');
            foreach (string line in lines)
            {
                int userProfileFound = line.IndexOf("All User Profile");
                if (userProfileFound > -1)
                {
                    string[] parts = line.Split(':');
                    if (parts.Length != 2)
                    {
                        continue;
                    }

                    profileNames.Add(parts[parts.Length - 1].Trim());
                }
            }

            return profileNames;
        }

        private static string GetPasswordForWifiProfile(string name)
        {
            var proc = new Process
            {
                StartInfo = new ProcessStartInfo
                {
                    FileName = "netsh.exe",
                    Arguments = "wlan show profile " + name.Trim() + " key=clear",
                    UseShellExecute = false,
                    RedirectStandardOutput = true,
                    CreateNoWindow = true
                }
            };

            proc.Start();
            string result = proc.StandardOutput.ReadToEnd();
            proc.WaitForExit();

            string[] lines = result.Split('\n');
            foreach (string line in lines)
            {
                int userProfileFound = line.IndexOf("Key Content");
                if (userProfileFound > -1)
                {
                    string[] parts = line.Split(':');
                    if (parts.Length != 2)
                    {
                        continue;
                    }

                    return parts[parts.Length - 1].Trim();
                }
            }

            return "?";
        }
    }
}