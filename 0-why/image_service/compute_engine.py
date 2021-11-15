import cv2
import numpy as np
import base64
from aiohttp import web, ClientSession, ClientTimeout

routes = web.RouteTableDef()

@routes.post('/')
async def get_image(request):
    request_n = await request.text()

    async with ClientSession(timeout=ClientTimeout(total=2)) as session:
        # NOTE what if fast_compute_service does not run on 127.0.0.1?
        async with session.post('http://127.0.0.1:8080/', data=request_n) as resp:
            fibonacci_result = await resp.text()

    image = np.ones((200, 600, 3), dtype=np.uint8) * 255
    font = cv2.FONT_HERSHEY_SIMPLEX

    org = (10, 50)
    fontScale = 1
    color = (255, 0, 0)
    thickness = 2

    image = cv2.putText(image, fibonacci_result, org, font, fontScale, color, thickness, cv2.LINE_AA)

    _, encoded_image = cv2.imencode(".jpg", image)
    base64_jpeg = base64.b64encode(encoded_image).decode("utf8")

    return web.Response(text=base64_jpeg)

app = web.Application()
app.add_routes(routes)
web.run_app(app, port=8081)
