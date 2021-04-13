import requests
import json
import sys


def data_display_string(data, batch):
    if not batch:
        if data['status'] == 'fail':
            return "ERROR: Could not locate address " + ip
        else:
            st = "--- Data for " + ip + " ---\n" + "Country: " + str(data['country']) + " - " + str(
                data['countryCode']) + "\n" + "Region: " + str(data['regionName']) + " - " + str(
                data['region']) + "\n" + "City: " + str(data['city']) + " - " + str(
                data['zip']) + "\n" + "Lat Long: (" + str(data['lat']) + ", " + str(
                data['lon']) + ")" + "\n" + "ISP: " + str(data['as']) + " - " + str(
                data['isp']) + "\n" + "Organisation: " + str(data['org']) + "\n" + "IP: " + str(data['query'])
            return st
    else:
        if data['status'] == 'fail':
            return "{" + ip + ":error" + "}"
        else:
            country = str(data['country']) + " - " + str(data['countryCode'])
            region = str(data['regionName']) + " - " + str(data['region'])
            city = str(data['city']) + " - " + str(data['zip'])
            latlong = str(data['lat']) + ", " + str(data['lon']) + ")"
            isp = str(data['as']) + " - " + str(data['isp'])
            org = str(data['org'])
            query = str(data['query'])
            st = (
                    "{{ip" + ":{{Country:{0},Region:{1},City:{2},Lat Long:{3},ISP:{4},Organisation:{5},IP:{6}}}" + "}}").format(
                country,
                region, city,
                latlong, isp, org, query)
            return st


args = sys.argv
batch_mode = False
addresses = []

if len(args) == 1:
    print("ERROR: No arguments given")
    sys.exit(-1)

for i in range(1, len(args)):
    arg = args[i]
    if arg == "-h" or arg == "--help" or arg == "-?":
        print("GeoIp Utility\nDeveloped by DrSmCraft")
        print("This utility is a commandline geolocation program.")
        print("It sends the query to http://ip-api.com and parses the response.\n")
        print("-?, --help  : Show this help message")
        print("-b, --batch : Show batch parsable output")
        sys.exit(0)
    elif arg == "-b" or arg == "--batch":
        batch_mode = True
    else:
        addresses.append(arg)

st = "["
count = 0
for ip in addresses:
    try:
        response = requests.get('http://ip-api.com/json/' + ip)
    except:
        print("ERROR: Could not get response from ip-api.com for query " + ip)
        continue

    data_string = response.content.decode('UTF-8')
    data = json.loads(data_string)

    d = data_display_string(data, batch_mode)

    if batch_mode:
        st += d
        if count < len(addresses) - 1:
            st += ","
    else:
        print(d)
    if not batch_mode:
        print()
    count += 1

st += "]"

if batch_mode:
    print(st)
