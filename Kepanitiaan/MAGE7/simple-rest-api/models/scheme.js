const mongoose = require('mongoose');

const dataScheme = mongoose.Schema({
    nama: String,
    nrp: Number,
    ipk: Number
});

module.exports = mongoose.model("dataMahasiswa", dataScheme);