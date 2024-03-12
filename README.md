# minishell


## Enum:

e_builtin_types: Bu enum, kabuğun (shell) içerisinde yer alan dahili komutları temsil eden sabit değerler kümesini tanımlar. Bu değerlere tamsayı tanımlayıcılar atanmıştır:

CD: Dizin değiştirme komutunu (cd) temsil eder (değer 1).
ENV: Çevre değişkenlerini gösteren komutu (env) temsil eder.
PWD: Mevcut çalışma dizinini gösteren komutu (pwd) temsil eder.
ECHO: Metni yazdıran komutu (echo) temsil eder.
EXIT: Kabuğu sonlandıran komutu (exit) temsil eder.
UNSET: Çevre değişkenlerini silen komutu (unset) temsil eder.
EXPORT: Çevre değişkenlerini kalıcı hale getiren komutu (export) temsil eder.
<br>
e_ttype: Bu enum, bir kabuk komut satırında bulunabilecek farklı token türlerini temsil eden sabit değerler kümesini tanımlar:

PIPE: Bir komutun çıktısını başka bir komutun girişine yönlendiren dikey çizgiyi (|) temsil eder.
STRING: Bir argüman veya komut adı olabilecek basit bir karakter dizisini temsil eder.
HERE_DOC: Metni doğrudan bir kabuk komutuna gömmeyi sağlayan bir mekanizmayı temsil eder.
RED_INPUT: Bir dosyadan bir komuta girişi (<) yönlendirmeyi temsil eder.
RED_APPEND: Bir komutun çıktısını bir dosyaya eklemeyi (>>) temsil eder.
RED_OUTPUT: Bir komutun çıktısını bir dosyanın üzerine yazmayı (>) temsil eder.

<br>

## Struct:

t_token: Bu struct, bir kabuk komut satırındaki bir token için veri tipini tanımlar. Aşağıdaki üyelere sahiptir:
str (karakter işaretçisi): Bu üye, tokenin gerçek dize değerini depolayan bir karakter dizisine işaret eder.
type (e_ttype enum üyesi): Bu üye, tokenin türünü (PIPE, STRING, vb.) e_ttype enum'da tanımlandığı gibi belirtir.
prev (t_token işaretçisi): Bu üye, bir token listesinin bir önceki tokenine işaret eder.
next (t_token işaretçisi): Bu üye, bir token listesinin bir sonraki tokenine işaret eder.


## Fonksiyonlar:

init_token: Bu fonksiyon, bir karakter işaretçisi (str) ve bir enum değeri (type) argüman olarak alır. Aşağıdaki adımları gerçekleştirir:

ft_calloc ( özel bir bellek tahsisi) kullanarak yeni bir t_token yapısı için bellek ayırır.
Yeni tokenin type üyesini verilen type değerine ayarlar.
str argümanını yeni tokenin str üyesine atar.
Yeni token henüz bir token listesinin parçası olmadığından prev ve next üyelerini NULL olarak başlatır.
Yeni oluşturulan t_token yapısına bir işaretçi döndürür.

<br>

token_addback: Bu fonksiyon iki argüman alır:

token (t_token işaretçisine işaretçi): Bu, bir token listesinin başına işaret eden bir çift işaretçidir.
new_token (t_token işaretçisi): Bu, listeye eklenmesi gereken yeni tokene işaret eder.
