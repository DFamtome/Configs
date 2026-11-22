-- Numérotation des lignes
vim.opt.number = true          -- Affiche les numéros de ligne

-- Indentation et tabulations
vim.opt.tabstop = 4            -- Largeur d'une tabulation
vim.opt.shiftwidth = 4         -- Largeur de l'indentation automatique
vim.opt.expandtab = true       -- Convertit les tabulations en espaces
vim.opt.smartindent = true     -- Indentation intelligente

-- Recherche
vim.opt.ignorecase = true      -- Ignore la casse lors d'une recherche
vim.opt.smartcase = true       -- Sauf si la recherche contient une majuscule

-- Interface et confort
vim.opt.cursorline = true      -- Surligne la ligne actuelle
vim.opt.clipboard = "unnamedplus" -- Partage le presse-papiers avec le système
vim.opt.mouse = "a"            -- Active le support de la souris

-- Active la coloration syntaxique (au cas où elle aurait été désactivée)
vim.cmd("syntax on")
vim.opt.termguicolors = true -- Activer la couleur syntaxique
vim.cmd("colorscheme habamax")

