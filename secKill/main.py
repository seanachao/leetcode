url = "https://cloud.cn2030.com/sc/wx/HandlerSubscribe.ashx?act=CustomerProduct&id=2998&lat=39.95933&lng=116.29845 "
url = "https://cloud.cn2030.com/sc/wx/HandlerSubscribe.ashx?act=GetCat1 "
cookies = {"ASP.NET_SessionId":"eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpYXQiOjE2NDc4NDEzMTUuNDU0OTg1NiwiZXhwIjoxNjQ3ODQ0OTE1LjQ1NDk4NTYsInN1YiI6IllOVy5WSVAiLCJqdGkiOiIyMDIyMDMyMTAxNDE1NSIsInZhbCI6IjFBaFNBUUlBQUFBUVlUYzRPREJrWXpWbU0yVmxaRFU1Wmh4dmNYSTFielZRUm0xNmRrbDFWSGwwUm5NM2FXSlVZV1pUZFZoRkFCeHZcclxuVlRJMldIUXRWbmhSTFZWRmNGRjZXV3hPZUhaQmFUUlVUMncwRFRFMU9TNHlNall1T1RVdU56RUFBQUFBQUFBQSJ9.BiDJXNJTLeVbL0kWtN5JPfVH7MH-Pb4pCGZz4UaAYBw"}
headers = {"User-Agent":"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36 MicroMessenger/7.0.9.501 NetType/WIFI MiniProgramEnv/Windows WindowsWechat"}
import requests
res = requests.get(url,headers = headers,cookies = cookies)
print(res.content)