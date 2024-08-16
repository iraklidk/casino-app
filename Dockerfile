FROM gcc:latest

WORKDIR /app

COPY . /app

RUN g++ -o casino-app ./CasinoPromotionCoreSystem/CasinoPromotionCoreSystem.cpp ./CasinoPromotionCoreSystem/Customer.cpp

CMD ["./casino-app"]