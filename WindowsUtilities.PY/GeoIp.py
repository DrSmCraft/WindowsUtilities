import requests
import json
import sys

args = sys.argv

if len(args) == 1:
    print("ERROR: No arguments given")
    sys.exit(-1)

for i in range(1, len(args)):

    ip = args[i]

    try:
        # response = requests.get('http://ip-api.com/json/24.169.326.59')
        response = requests.get('http://ip-api.com/json/' + ip)
        # response = requests.get('http://ip-api.com/json/youtube.com')

    except:
        print("ERROR: Could not get response from ip-api.com for query " + ip)
        continue

    data_string = response.content.decode('UTF-8')
    data = json.loads(data_string)

    if data['status'] == 'fail':
        print("ERROR: Could not locate address " + ip)
        continue
    else:
        print("--- Data for " + ip + " ---")
        print("Country: " + str(data['country']) + " - " + str(data['countryCode']))
        print("Region: " + str(data['regionName']) + " - " + str(data['region']))
        print("City: " + str(data['city']) + " - " + str(data['zip']))
        print("Lat Long: (" + str(data['lat']) + ", " + str(data['lon']) + ")")
        print("ISP: " + str(data['as']) + " - " + str(data['isp']))
        print("Organisation: " + str(data['org']))
        print("IP: " + str(data['query']))
    print()

