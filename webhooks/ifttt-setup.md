# Configuración de Webhooks en IFTTT para Controlar LEDs con ESP32

## 1. Crear una Cuenta en IFTTT
1. Visita [IFTTT](https://ifttt.com/) y crea una cuenta si aún no la tienes.
2. Una vez registrada, inicia sesión en tu cuenta de IFTTT.

## 2. Configurar Webhooks
1. Ve a la página de [Webhooks](https://ifttt.com/maker_webhooks) en IFTTT.
2. Haz clic en "Connect" para activar el servicio de Webhooks.

## 3. Crear un Applet para Encender un LED
1. Haz clic en "Create" en la parte superior de la página de IFTTT.
2. Selecciona "+ This" para definir el disparador.
3. Elige "Google Assistant" como servicio, dependiendo de qué asistente estés usando.
4. Configura el comando de voz que utilizarás, por ejemplo: `"Encender el LED 1"`.
5. Luego selecciona "+ That" para definir la acción.
6. Busca y selecciona "Webhooks" como el servicio de acción.
7. Elige la acción "Make a web request".
8. Configura la solicitud web con los siguientes parámetros:
    - **URL**: `http://<Tu_IP>/led1on`
    - **Method**: `GET`
    - **Content Type**: `text/plain`
    - **Body**: (Déjalo vacío)
9. Guarda el applet y prueba el comando de voz.

## 4. Crear Applets para Apagar y Controlar el Segundo LED
- Repite los pasos anteriores, pero cambia el comando de voz y la URL según corresponda:
  - **Apagar LED 1**: `http://<Tu_IP>/led1off`
  - **Encender LED 2**: `http://<Tu_IP>/led2on`
  - **Apagar LED 2**: `http://<Tu_IP>/led2off`

## 5. Prueba y Solución de Problemas
- Asegúrate de que tu ESP32 esté conectado a la red y que la IP utilizada en los Webhooks sea correcta.
- Prueba cada comando de voz y verifica que el LED correspondiente responda correctamente.
- Si tienes problemas, revisa la consola serie de tu ESP32 para ver mensajes de error o conexión.

