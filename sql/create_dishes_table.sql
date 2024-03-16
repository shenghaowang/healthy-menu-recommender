CREATE TABLE IF NOT EXISTS dishes (
    dish_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
    dish_name VARCHAR(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
    ingredients VARCHAR(512) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL DEFAULT '',
    calories INT UNSIGNED NOT NULL DEFAULT 0,
    carbohydrate DECIMAL(5,2) NOT NULL DEFAULT 0.00,
    protein DECIMAL(5,2) NOT NULL DEFAULT 0.00,
    fat DECIMAL(5,2) NOT NULL DEFAULT 0.00,
    cellulose DECIMAL(5,2) NOT NULL DEFAULT 0.00,
    photo VARCHAR(255) NOT NULL DEFAULT '',
    PRIMARY KEY (dish_id)
) CHARACTER SET = utf8;