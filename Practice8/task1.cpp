struct hacked_object {
    int trash, secret;
};

int hack_it(Keeper keeper) {
    hacked_object *hack = reinterpret_cast<hacked_object*>(&keeper);
    return hack->secret;
}
