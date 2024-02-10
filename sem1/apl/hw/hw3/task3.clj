; Import the IO library
(require '[clojure.java.io :as io])

(defn scan [path]
    ; We use (io/file path) to convert String to Path, and use .toString to
    ; perform the inverse conversion.
    ;
    ; First, check with .isDirectory whether our path is a directory or a
    ; regular file
    (if (.isDirectory (io/file path))
        ; If this is a directory, the scan its entries using .list
        (doseq [sub (.list (io/file path))]
            (let [sub (str (.toString path) "/" (.toString sub))]
                (scan (.toString sub))))
        ; Otherwise, use slurp to read the contents of the file entirely. Then,
        ; use .contains to find the requied substring "hello"
        (let
            [s (slurp path)]
            (when (.contains s "hello")
                (println path)))))

; Just start recursive scan for directory test
(scan "test")
