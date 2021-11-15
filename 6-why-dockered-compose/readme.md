# Hellsoft

Hellsoft projekt demonstruje motivaci k použití Dockeru - měl by ukázat **proč a na co se hodí Docker**. 

Hellsoft je složen z:

1. Frontendu `frontend`
1. C++ výpočetní služby `fast_compute_service`
1. Python služby pro práci s obrazovými daty `image_service`
1. Nginx reverzní proxy

Pro spuštění *stačí* zkompilovat a spustit `fast_compute_service`, `image_service` a `frontend`. Jo a nezapomenout na reverzní proxy Nginx.

Je potřeba hlídat, zda všechny služby běží správně a po pádu je znova spustit. Jo a taky je potřeba logovat výstup každé služby a ideálně logy rotovat, aby to nesežralo místo na disku :-).

Deploy jsem už neřešil, prostě zákazníkovi pošleme můj komp, protože to **na mém kompu funguje dobře**...
